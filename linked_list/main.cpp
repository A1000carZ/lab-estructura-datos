#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

struct Node
{
    int value;
    Node *right;
};

void printNode(Node *node);
void insertRight(Node *node);
Node *insertLeft(Node *node);
void insertRandomRight(Node *node);
Node *insertRandomLeft(Node *node);
void totalSum(Node *node);
void searchAndReplace(Node *node);
Node *insertBeforeNum(Node *node);
Node *insertAfterNum(Node *node);
Node *deleteLastNode(Node *node);
Node *deleteFirstNode(Node *node);
Node *findAndDeleteNode(Node *node);
bool searchNode(int value, Node *node);
int main()
{

    Node *node = new (Node);
    node->value = 0;
    node->right = NULL;
    int answer;

    while (1)
    {
        cout << "\tMenu" << endl;
        printNode(node);
        cout << endl
             << "\t1. Imprimir nodo actual" << endl;
        cout << "\t2. Insertar nodo a la derecha" << endl;
        cout << "\t3. Insertar nodo a la izquierda" << endl;
        cout << "\t4. Insertar nodos aleatorios a la derecha" << endl;
        cout << "\t5. Insertar nodos aleatorios a la izquierda" << endl;
        cout << "\t6. Mostrar sumatoria total" << endl;
        cout << "\t7. Buscar un valor" << endl;
        cout << "\t8. Insertar nodo antes del nodo" << endl;
        cout << "\t9. Insertar nodo despues del nodo" << endl;
        cout << "\t10. Eliminar el ultimo nodo" << endl;
        cout << "\t11. Eliminar el primer nodo" << endl;
        cout << "\t12. Eliminar nodo especifico" << endl;
        cout << endl
             << "\tSelecciona una opcion: ";
        cin >> answer;
        switch (answer)
        {
        case 1:
            printNode(node);
            break;
        case 2:
            insertRight(node);
            break;
        case 3:
            node = insertLeft(node);
            break;
        case 4:
            insertRandomRight(node);
            break;
        case 5:
            node = insertRandomLeft(node);
            break;
        case 6:
            totalSum(node);
            break;
        case 7:
            searchAndReplace(node);
            break;
        case 8:
            node = insertBeforeNum(node);
            break;
        case 9:
            node = insertAfterNum(node);
            break;
        case 10:
            node = deleteLastNode(node);
            break;
        case 11:
            node = deleteFirstNode(node);
            break;
        case 12:
            node = findAndDeleteNode(node);
            break;
        default:
            cout << "Lo siento, no pudimos procesar su respuesta" << endl;
            break;
        }

        system("clear");
    }

    return 0;
}

bool searchNode(int value, Node *node)
{
    Node *temp;
    temp = node;
    bool founded = false;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            founded = true;
            break;
        }
    }
    return founded;
}

void printNode(Node *node)
{
    Node *temp;
    temp = node;
    if (node->value == 0)
    {
        int value;
        cout << "\tVamos a inicializar el nodo" << endl;
        cout << "\tIngresa un valor inicial: ";
        cin >> value;
        node->value = value;
        system("clear");
    }
    cout << endl
         << "\tEstatus actual" << endl;
    cout << "\t";
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->right != NULL)
            cout << " 👉 ";
        temp = temp->right;
    }
    cout << endl;
}

void insertRight(Node *node)
{
    Node *temp = new (Node);
    Node *lastNode = node;
    while (lastNode->right != NULL)
    {
        lastNode = lastNode->right;
    }
    cout << "\tIngresa el numero a agregar: ";
    cin >> temp->value;
    temp->right = NULL;
    lastNode->right = temp;
}

Node *insertLeft(Node *node)
{
    Node *temp = new (Node);
    Node *firstNode = node;

    cout << "\tIngresa el numero a agregar: ";
    cin >> temp->value;
    temp->right = firstNode;

    return temp;
}

void insertRandomRight(Node *node)
{
    int count;
    cout << "\tCuantos datos aleatorios deseas agregar: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        Node *temp = new (Node);
        Node *lastNode = node;
        while (lastNode->right != NULL)
        {
            lastNode = lastNode->right;
        }
        temp->value = 1 + rand() % 100;
        temp->right = NULL;
        lastNode->right = temp;
    }
}

Node *insertRandomLeft(Node *node)
{
    int count;
    Node *firstNode = node;
    cout << "\tCuantos datos aleatorios deseas agregar: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        Node *temp = new (Node);
        temp->value = 1 + rand() % 100;
        temp->right = firstNode;
        firstNode = temp;
    }

    return firstNode;
}

void totalSum(Node *node)
{
    int sum = 0;
    Node *temp = node;
    while (temp != NULL)
    {
        sum += temp->value;
        temp = temp->right;
        /* code */
    }
    cout << "\tLa sumatoria total es de: " << sum << endl;
    sleep(3);
}

void searchAndReplace(Node *node)
{
    Node *temp = node;
    int value, newValue;
    char answer;
    bool founded = false;
    cout << "\tIngresa el numero a buscar: ";
    cin >> value;
    cout << endl;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            founded = true;
            cout << "\tEl numero " << value << " esta en la lista!" << endl;
            cout << "\tLo deseas reemplazar [s] si | [n] no : ";
            cin >> answer;
            cout << endl;
            if (answer == 's' || answer == 'S')
            {
                cout << "\tIngresa el nuevo valor: ";
                cin >> newValue;
                temp->value = newValue;
                value = newValue;
            }
            break;
        }
        temp = temp->right;
    }
    if (!founded)
    {
        cout << "\tLo siento el numero " << value << " no se encuentra en la lista" << endl;
    }
}

Node *insertBeforeNum(Node *node)
{
    int value, newValue;
    cout << "\tIngresa el numero antes del cual quieres agregar el nuevo numero: ";
    cin >> value;
    cout << "\tIngresa el nuevo numero: ";
    cin >> newValue;
    Node *temp = node;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            Node *newNode = new (Node);
            newNode->value = newValue;
            newNode->right = temp;
            if (prev == NULL)
            {
                return newNode;
            }
            else
            {
                prev->right = newNode;
                return node;
            }
        }
        prev = temp;
        temp = temp->right;
    }
    cout << "\tNo se encontro el numero " << value << endl;
    return node;
}

Node *insertAfterNum(Node *node)
{
    int value, newValue;
    cout << "\tIngresa el numero despues del cual quieres agregar el nuevo numero: ";
    cin >> value;
    cout << "\tIngresa el nuevo numero: ";
    cin >> newValue;
    Node *temp = node;
    while (temp != NULL)
    {
        if (temp->value == value)
        {
            Node *newNode = new (Node);
            newNode->value = newValue;
            newNode->right = temp->right;
            temp->right = newNode;
            return node;
        }
        temp = temp->right;
    }
    cout << "\tNo se encontro el numero " << value << endl;
    return node;
}

Node *deleteLastNode(Node *node)
{
    Node *temp;
    Node *lastNode;
    temp = node;
    if (temp->right == NULL)
    {
        delete (temp);
        node = NULL;
    }
    else
    {
        while (temp->right != NULL)
        {
            lastNode = temp;
            temp = temp->right;
        }
        lastNode->right = NULL;
        delete (temp);
    }

    return node;
}

Node *deleteFirstNode(Node *node)
{
    Node *temp;
    Node *initialNode;
    temp = node;
    if (temp->right == NULL)
    {
        delete (temp);
        node = NULL;
    }
    else
    {
        node = node->right;
        temp->right = NULL;
        delete (temp);
    }
    return node;
}

Node *findAndDeleteNode(Node *node)
{
    Node *temp;
    temp = node;
    Node *beforeNode = NULL;
    int value;
    cout << "\tIngresa el valor a eliminar: ";
    cin >> value;
    
    while (temp!=NULL)
    {
        if (temp->value == value)
        {
            if (temp->right == NULL && temp == node)
            {
                cout << "Cierto"<<endl;
                delete(temp);
                node = NULL;
            }
            else{
                if(temp == node){
                    node = temp->right;
                    temp->right = NULL;
                    delete(temp);
                }
                else{
                    if(temp->right == NULL){
                        beforeNode->right=NULL;
                        delete(temp);
                    }
                    else{
                        beforeNode->right = temp->right;
                        temp->right=NULL;
                        delete(temp);
                    }
                }
            }
            return node;
            /* code */
        }
        beforeNode = temp;
        temp=temp->right;
    }
    cout << "\tLo siento no pudimos encontrar el valor"<<endl;
    sleep(1);
    return node;
}