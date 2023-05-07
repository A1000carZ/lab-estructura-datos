#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;

class User
{
private:
    string email;
    string username;
    string password;

public:
    string getEmail(){
        return email;
    }
    string getUsername(){
        return username;
    }
    void setEmail(string u)
    {
        email = u;
    }
    void setUsername(string u)
    {
        username = u;
    }
    void setPassword()
    {
        password = getpass("Ingrese su contraseña: ");
    }

    bool isValid()
    {
        if (username != "" && email != "")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool signIn(string emailField, string passwordField)
    {
        if (emailField == email && passwordField == password)
        {
            return true;
        }
        else if (emailField == email && passwordField != password)
        {
            cout << "Contrasenia erronea";
            return false;
        }
        else
        {
            return false;
        }
    }
};

struct transaction
{
    float amount;
    string description;
    string date;
};

struct withdrawalWithoutCard
{
    string id;
    string pin;
    float amount;
};

class BankAccount
{
private:
    User user;
    float balance;
    vector<transaction> transactions;
    vector<withdrawalWithoutCard> withdrawals;

public:
    void deposit(float amount,string description){
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);
        std::tm time_info = *std::localtime(&current_time);
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d", &time_info);
        transaction newTransaction;
        balance = balance + amount;
        newTransaction.amount = amount;
        newTransaction.description = description;
        newTransaction.date = buffer;
        transactions.push_back(newTransaction);
        cout << "operacion exitosa";
    }
    void transfer(float amount, string description)
    {
        auto now = std::chrono::system_clock::now();
        std::time_t current_time = std::chrono::system_clock::to_time_t(now);
        std::tm time_info = *std::localtime(&current_time);
        char buffer[80];
        std::strftime(buffer, 80, "%Y-%m-%d", &time_info);
        transaction newTransaction;
        balance = balance - amount;
        newTransaction.amount = amount;
        newTransaction.description = description;
        newTransaction.date = buffer;
        transactions.push_back(newTransaction);
        cout << "operacion exitosa";
    }
    withdrawalWithoutCard wWithoutCard(float amount)
    {
        withdrawalWithoutCard newWWCard;
        string id = "";
        string pin = "";
        srand(time(nullptr));
        for (int i = 0; i < 10; i++)
        {
            int digit = rand() % 10;
            id += to_string(digit);
        }

        for (int i = 0; i < 4; i++)
        {
            int digit = rand() % 10;
            pin += to_string(digit);
        }

        newWWCard.amount = amount;
        newWWCard.id = id;
        newWWCard.pin = pin;

        withdrawals.push_back(newWWCard);
        return newWWCard;
    }
    User getUser()
    {
        return user;
    }

    void setUser(User u)
    {
        user = u;
    }
};

struct Accounts
{
    BankAccount value;
    Accounts *next;
    Accounts *prev;
};
Accounts* addAccount(Accounts* accounts, BankAccount account);
User createUser();
BankAccount searchAccount(string email,Accounts*accounts);
BankAccount login(Accounts *accounts);

int main()
{
    bool isAuthenticated = false;
    User newUser;
    User user;
    Accounts* accounts;
    BankAccount currentAccount;
    int choiceAuth;
    int menuChoice;
    while (true)
    {
        if (isAuthenticated && currentAccount.getUser().isValid())
        {
            cout << "Bienvenido "<<currentAccount.getUser().getUsername()<<" !"<<endl;
            cout << "1.Cerrar sesion"<<endl;
            cout << "Seleccione una opcion: ";
            cin >> menuChoice;
            switch (menuChoice)
            {
            case 1:
                isAuthenticated = false;
                system("cls");
                break;
            
            default:
                cout << "No pudimos procesar su respuesta";
                break;
            }
            system("clear"); 
        }
        else
        {
            cout << " BIENVENIDO AL BANCOIN \n";
            cout << "1. Iniciar sesion" << endl;
            cout << "2. Crear cuenta" << endl;
            cout << "Seleccione una opcion: ";
            cin >> choiceAuth;
            cout << endl;
            switch (choiceAuth)
            {
            case 1:
                currentAccount = login(accounts);
                if(currentAccount.getUser().isValid()){
                    isAuthenticated = true;
                }
                break;
            case 2:
                newUser = createUser();
                if (newUser.isValid())
                {
                    BankAccount newBankAccount;
                    newBankAccount.setUser(newUser);
                    currentAccount = newBankAccount;
                    accounts = addAccount(accounts,newBankAccount);
                    isAuthenticated = true;
                }
                break;
            default:
                break;
            }
            system("clear");
        }
    }

    return 0;
}

Accounts* addAccount(Accounts* accounts, BankAccount account) {
    Accounts* newAccount = new Accounts;
    newAccount->value = account;
    newAccount->next = accounts;
    newAccount->prev = nullptr;
    if (accounts != nullptr) {
        accounts->prev = newAccount;
    }
    accounts = newAccount;

    return accounts;
}

User createUser()
{
    User newUser;
    string username;
    string email;
    fflush(stdin);
    cout << "Crear cuenta" << endl;
    cout << "Ingrese su nombre: ";
    getline(cin,username);
    cout << "Ingrese su email: ";
    cin >> email;
    newUser.setEmail(email);
    newUser.setUsername(username);
    newUser.setPassword();
    return newUser;
}
BankAccount searchAccount(string email, Accounts *accounts)
    {
        Accounts *curr = accounts;
        BankAccount account;
        while (curr != nullptr)
        {
            if (curr->value.getUser().getEmail() == email)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        BankAccount errorAccount;
        return errorAccount;
}
User searchUser(string email, Accounts *accounts)
    {
        Accounts *curr = accounts;
        while (curr != nullptr)
        {
            if (curr->value.getUser().getEmail() == email)
            {
                return curr->value.getUser();
            }
            curr = curr->next;
        }
        User dummyUser;
        return dummyUser;
    }

BankAccount login(Accounts *accounts)
{
    BankAccount account;
    string emailField;
    string passwordField;
    cout << "Ingrese su email: ";
    cin >> emailField;
    cout << endl;
    cout << "Ingrese su contrasenia: ";
    cin >> passwordField;
    cout << endl;

    User user = searchUser(emailField,accounts);

    if (user.signIn(emailField, passwordField))
    {
        return searchAccount(emailField,accounts);
    }
    else
    {
        BankAccount errorAccount;
        return errorAccount;
    }
}