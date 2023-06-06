#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#define CURL_STATICLIB
#include <curl/curl.h>
using namespace std;

class User
{
private:
    string email;
    string username;
    string password;

public:
    string getEmail()
    {
        return email;
    }
    string getUsername()
    {
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
            sleep(6);
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
    string type;
};

struct withdrawalWithoutCard
{
    User user;
    string id;
    string pin;
    bool status;
    float amount;
};
struct BankWWCard
{
    withdrawalWithoutCard value;
    BankWWCard *next;
    BankWWCard *prev;
};

class BankAccount
{
private:
    User user;
    string key;
    float balance;
    vector<transaction> transactions;
    BankWWCard *withdrawals;

public:
    void addWWCard(withdrawalWithoutCard wWCard)
    {
        BankWWCard *newBWWCard = new BankWWCard;

        if (withdrawals == NULL)
        {
            newBWWCard->value = wWCard;
            newBWWCard->next = NULL;
            newBWWCard->prev = NULL;
        }
        newBWWCard->value = wWCard;
        newBWWCard->next = withdrawals;
        newBWWCard->prev = nullptr;
        if (withdrawals != nullptr)
        {
            withdrawals->prev = newBWWCard;
        }
        withdrawals = newBWWCard;
    }
    void printTransactions()
    {
        string answer;
        system("clear");
        // Print table header
        cout << setw(5) << setfill(' ') << "No."
             << setw(20) << setfill(' ') << "Tipo"
             << setw(20) << setfill(' ') << "Desripcion"
             << setw(10) << setfill(' ') << "Monto"
             << setw(30) << setfill(' ') << "Fecha"
             << endl;
        cout << setfill('-') << setw(70) << "" << endl;

        // Print table rows
        for (int i = 0; i < transactions.size(); i++)
        {
            cout << setfill(' ') << setw(5) << i + 1
                 << setw(20) << transactions[i].type
                 << setw(20) << transactions[i].description
                 << setw(10) << "$" << fixed << setprecision(2) << transactions[i].amount
                 << setw(30) << transactions[i].date
                 << endl;
        }
        cout << "Presione [s] para continuar: ";
        cin >> answer;
    }
    string getKey()
    {
        return key;
    }
    string getBalance()
    {
        return to_string(balance);
    }
    void deposit(float amount, string description)
    {
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
        newTransaction.type = "deposito";
        transactions.push_back(newTransaction);
        cout << "operacion exitosa";
        sleep(1);
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
        newTransaction.type = "retiro";
        transactions.push_back(newTransaction);
        cout << "operacion exitosa";
    }
    withdrawalWithoutCard wWithoutCard()
    {
        withdrawalWithoutCard newWWCard;
        string id = "";
        string pin = "";
        string choice;
        float amount;
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
        system("clear");
        cout << "Ingrese el monto a retirar: ";
        cin >> amount;
        cout << endl;
        cout << "Retiro generado!" << endl;
        newWWCard.amount = amount;
        newWWCard.id = id;
        newWWCard.pin = pin;
        newWWCard.user = user;
        newWWCard.status = false;
        cout << "Este es el id: " << id << endl;
        cout << "Este es el pin: " << pin << endl;
        cout << "Es importante que guarde estos datos" << endl;
        cout << "Escriba la tecla [ s ] :";
        cin >> choice;
        return newWWCard;
    }
    User getUser()
    {
        return user;
    }
    void setKey(string u)
    {
        key = u;
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

Accounts *addAccount(Accounts *accounts, BankAccount account);
User createUser();
Accounts *searchAccount(string email, Accounts *accounts);
Accounts *login(Accounts *accounts);
Accounts *wWCardFunction(Accounts *accounts, BankWWCard *bankWWCard);
BankWWCard *addWWCard(BankWWCard *bankWWCard, withdrawalWithoutCard wWCard);
BankWWCard *searchWWCard(BankWWCard *bankWWCard, string id);
Accounts *searchAccountByKey(string key, Accounts *accounts);
void printTransactions(BankAccount bankAccount);
void deposit(Accounts *currentAccount);
void transfer(Accounts *currentAccounts, Accounts *currentAccount);
size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata);
void sendMSG(string to, string message);
bool send_email(const std::string &from_address,
                const std::string &to_address,
                const std::string &subject,
                const std::string &body,
                const std::string &gmail_username,
                const std::string &gmail_password);

int main()
{
    bool isAuthenticated = false;
    User newUser;
    User user;
    Accounts *accounts;
    Accounts *currentAccount;
    BankWWCard *bankWWCards = NULL;
    int choiceAuth;
    int menuChoice;
    while (true)
    {
        if (isAuthenticated && currentAccount->value.getUser().isValid())
        {
            cout << "BanCoin" << endl
                 << endl;
            cout << "Bienvenido " << currentAccount->value.getUser().getUsername() << "!" << endl;
            cout << "Balance actual: $" << currentAccount->value.getBalance() << " MXN" << endl;
            cout << "Clabe interbancaria: " << currentAccount->value.getKey() << endl;
            cout << "1. Depositar" << endl;
            cout << "2. Transferir" << endl;
            cout << "3. Retiro sin tarjeta" << endl;
            cout << "4. Transacciones" << endl;
            cout << "5. Cerrar sesion" << endl;
            cout << "Seleccione una opcion: ";
            cin >> menuChoice;
            switch (menuChoice)
            {
            case 1:
                deposit(currentAccount);
                break;
            case 2:
                transfer(accounts, currentAccount);
                break;
            case 3:
                bankWWCards = addWWCard(bankWWCards, currentAccount->value.wWithoutCard());
                break;
            case 4:
                currentAccount->value.printTransactions();
                system("cls");
                break;
            case 5:
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
            cout << "Bienvenido a BanCoin \n";
            cout << "1. Iniciar sesion" << endl;
            cout << "2. Crear cuenta" << endl;
            cout << "3. Retiro sin tarjeta" << endl;
            cout << "Seleccione una opcion: ";
            cin >> choiceAuth;
            cout << endl;
            switch (choiceAuth)
            {
            case 1:
                currentAccount = login(accounts);
                if (currentAccount != NULL)
                {
                    isAuthenticated = true;
                }
                break;
            case 2:
                newUser = createUser();
                if (newUser.isValid())
                {
                    string key = "";
                    const char charset[] =
                        "0123456789"
                        "abcdefghijklmnopqrstuvwxyz"
                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    const int max_index = sizeof(charset) - 1;
                    srand(time(0));
                    for (int i = 0; i < 10; i++)
                    {
                        key += charset[rand() % max_index];
                    }
                    BankAccount newBankAccount;
                    newBankAccount.setUser(newUser);
                    newBankAccount.setKey(key);
                    // currentAccount = newBankAccount;
                    accounts = addAccount(accounts, newBankAccount);
                    currentAccount = searchAccount(newBankAccount.getUser().getEmail(), accounts);
                    if (currentAccount != NULL)
                    {
                        bool success = send_email("a1000carzh@gmail.com", "amilcarzsanchezv@gmail.com", "Test email", "This is a test email.", "a1000carzh@gmail.com", "iychaddzqjpofraq");

                        if (success)
                        {
                            std::cout << "Email sent successfully." << std::endl;
                        }
                        else
                        {
                            std::cerr << "Error sending email." << std::endl;
                        }
                        isAuthenticated = true;
                        sleep(2);
                    }
                }
                break;
            case 3:
                accounts = wWCardFunction(accounts, bankWWCards);
                break;
            default:
                cout << "No pudimos procesar su respuesta";
                break;
            }
            system("clear");
        }
    }

    return 0;
}

size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    std::string *response = (std::string *)userdata;
    response->append(ptr, size * nmemb);
    return size * nmemb;
}

// Function to send an email using curl
bool send_email(const std::string &from_address,
                const std::string &to_address,
                const std::string &subject,
                const std::string &body,
                const std::string &gmail_username,
                const std::string &gmail_password)
{
    CURL *curl;
    CURLcode res = CURLE_OK;

    // Set up the curl object
    curl = curl_easy_init();
    if (curl)
    {
        // Set the URL for the Gmail SMTP server
        curl_easy_setopt(curl, CURLOPT_URL, "smtps://smtp.gmail.com:587");

        // Set the email credentials
        curl_easy_setopt(curl, CURLOPT_USERNAME, gmail_username.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, gmail_password.c_str());

        // Set the email headers
        struct curl_slist *recipients = NULL;
        std::string to_header = "To: " + to_address;
        recipients = curl_slist_append(recipients, to_header.c_str());
        std::string from_header = "From: " + from_address;
        recipients = curl_slist_append(recipients, from_header.c_str());
        std::string subject_header = "Subject: " + subject;
        recipients = curl_slist_append(recipients, subject_header.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        // Set the email body
        std::vector<char> buffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.size());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

        // Send the email
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            cout << "response: "<<res<<endl;
            curl_slist_free_all(recipients);
            curl_easy_cleanup(curl);
            return false;
        }

        // Clean up
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);

        return true;
    }
    else
    {
        return false;
    }
}
void sendMSG(string to, string message)
{
    string toMsg = "whatsapp:+521" + to;
    cout << toMsg << endl;
    //send_whatsapp_message("AC8602d3fbaf1a819a4db1c9b2b84262d7", "cd9c6c94633effee4f6d76cddfcc6c0c", toMsg, "whatsapp:+14155238886", message);
    sleep(2);
}

void transfer(Accounts *currentAccounts, Accounts *currentAccount)
{
    float amount;
    string key;
    string description;
    Accounts *account = new (Accounts);
    cout << "Ingresa la clabe interbancaria: ";
    cin >> key;
    cout << "Ingresa el monto a depositar: ";
    cin >> amount;
    fflush(stdin);
    cout << "Ingresa el concepto: ";
    getline(cin, description);

    account = searchAccountByKey(key, currentAccounts);
    if (account != NULL)
    {
        currentAccount->value.transfer(amount, description);
        account->value.deposit(amount, description);
        cout << "operacion exitosa";
    }
    else
    {
        cout << "Lo siento no pudimos encontrar la cuenta";
    }

    sleep(1);
}

void deposit(Accounts *currentAccount)
{
    float amount;
    string description;
    cout << "Ingresa el monto a depositar: ";
    cin >> amount;
    fflush(stdin);
    cout << "Ingresa el concepto: ";
    getline(cin, description);
    currentAccount->value.deposit(amount, description);
    cout << "operacion exitosa";
    sleep(1);
}

BankWWCard *addWWCard(BankWWCard *bankWWCard, withdrawalWithoutCard wWCard)
{
    BankWWCard *newBWWCard = new BankWWCard;
    if (bankWWCard == NULL)
    {
        newBWWCard->value = wWCard;
        newBWWCard->next = NULL;
        newBWWCard->prev = NULL;
        return newBWWCard;
    }
    newBWWCard->value = wWCard;
    newBWWCard->next = bankWWCard;
    newBWWCard->prev = nullptr;
    if (bankWWCard != nullptr)
    {
        bankWWCard->prev = newBWWCard;
    }
    bankWWCard = newBWWCard;

    return bankWWCard;
}
BankWWCard *searchWWCard(BankWWCard *bankWWCard, string id)
{
    BankWWCard *curr = bankWWCard;
    BankAccount account;
    while (curr != nullptr)
    {
        if (curr->value.id == id)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

Accounts *wWCardFunction(Accounts *accounts, BankWWCard *bankWWCard)
{

    BankWWCard *item;
    Accounts *currentAccount;
    string id, pin;
    system("clear");
    cout << "Ingrese el id: ";
    cin >> id;
    cout << "Ingrese el pin: ";
    cin >> pin;

    item = searchWWCard(bankWWCard, id);

    if (item != NULL)
    {
        cout << "id: " << item->value.id << endl;
        cout << "Monto a cobrar: $" << item->value.amount << endl;
        cout << "Por favor revise su efectivo" << endl;
        currentAccount = searchAccount(item->value.user.getEmail(), accounts);
        currentAccount->value.transfer(item->value.amount, "Retiro sin tarjeta");
        sleep(5);
        return accounts;
    }
    else
    {
        cout << "Verifique sus datos" << endl;
        sleep(10);
        return accounts;
    }
}

Accounts *addAccount(Accounts *accounts, BankAccount account)
{
    Accounts *newAccount = new Accounts;
    newAccount->value = account;
    newAccount->next = accounts;
    newAccount->prev = nullptr;
    if (accounts != nullptr)
    {
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
    getline(cin, username);
    cout << "Ingrese su email: ";
    cin >> email;
    newUser.setEmail(email);
    newUser.setUsername(username);
    newUser.setPassword();

    return newUser;
}
Accounts *searchAccountByKey(string key, Accounts *accounts)
{
    Accounts *curr = accounts;
    BankAccount account;
    while (curr != nullptr)
    {
        if (curr->value.getKey() == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

Accounts *searchAccount(string email, Accounts *accounts)
{
    Accounts *curr = accounts;
    BankAccount account;
    while (curr != nullptr)
    {
        if (curr->value.getUser().getEmail() == email)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
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

Accounts *login(Accounts *accounts)
{
    BankAccount account;
    string emailField;
    string passwordField;
    cout << "Ingrese su email: ";
    cin >> emailField;
    cout << endl;
    passwordField = getpass("Ingrese su contraseña: ");
    cout << endl;

    User user = searchUser(emailField, accounts);

    if (user.signIn(emailField, passwordField))
    {
        return searchAccount(emailField, accounts);
    }
    else
    {
        return NULL;
    }
}