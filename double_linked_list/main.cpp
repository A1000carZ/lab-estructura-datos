#include <iostream>
#include <time.h>
#include <unistd.h>
using namespace std;

struct Node
{
    int value;
    Node *right;
    Node *left;
};

void printLeftToRightNode(Node *node);
void printRightToLeftNode(Node *node);
Node* insertRight(Node *node);
void insertLeft(Node *node);
void insertRandomRight(Node *node);
Node *insertRandomLeft(Node *node);

int main()
{
    Node *firstNode = new (Node);
    Node *lastNode = new(Node);
    int answer;
    while (1)
    {
        cout << "\tMenu" << endl;
        printLeftToRightNode(firstNode);
        cout << endl << "\t1. Imprimir nodo actual de izquierda a derecha" << endl;
        cout << "\t2. Imprimir nodo actual de derecha a izquierda" << endl;
        cout << "\t3. Insertar nodo a la derecha" << endl;
        cout << "\t4. Insertar nodo a la izquierda" << endl;
        cout << "\t5. Insertar nodos aleatorios a la derecha" << endl;
        cout << "\t6. Insertar nodos aleatorios a la izquierda" << endl;
        cout << endl << "\tSelecciona una opcion: ";
        cin >> answer;
        switch (answer)
        {
        case 1:
            printLeftToRightNode(firstNode);
            break;
        case 2:
            printRightToLeftNode(lastNode);
            break;
        case 3:
            lastNode = insertRight(lastNode);
            break;
        case 4:
            insertLeft(firstNode);
            break;
        case 5:
            insertRandomRight(firstNode);
            break;
        case 6:
            firstNode = insertRandomLeft(firstNode);
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

void printLeftToRightNode(Node *node)
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


void printRightToLeftNode(Node *node)
{
   Node *temp;
    temp = node;
    cout << endl
         << "\tEstatus actual" << endl;
    cout << "\t";
    while (temp != NULL)
    {
        cout << temp->value;
        if (temp->left != NULL)
            cout << " 👉 ";
        temp = temp->left;
    }
    cout << endl;
    sleep(1);
}



Node* insertRight(Node *lastNode)
{
     int value;
    cout << "\tIngresa el valor del nodo: ";
    cin >> value;
    Node *newNode = new Node;
    newNode->value = value;
    newNode->left = lastNode;
    lastNode->right = newNode;
    lastNode = newNode;
    return lastNode;
}

void insertLeft(Node *firstNode)
{
    int value;
    cout << "\tIngresa el valor del nodo: ";
    cin >> value;
    Node *newNode = new Node;
    newNode->value = value;
    newNode->right = firstNode;
    firstNode->left = newNode;
    firstNode = newNode;
}



void insertRandomRight(Node *node)
{
     int numNodes;
    cout << "\tIngresa la cantidad de nodos a insertar: ";
    cin >> numNodes;
    Node *lastNode = node;
    while (lastNode->right != NULL)
        lastNode = lastNode->right;
    for (int i = 0; i < numNodes; i++)
    {
        int value = rand() % 100 + 1;
        Node *newNode = new Node;
        newNode->value = value;
        newNode->left = lastNode;
        lastNode->right = newNode;
        lastNode = newNode;
    }
}

Node *insertRandomLeft(Node *node)
{
   int n;
    cout << "\tIngresa la cantidad de nodos que deseas insertar: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Node *newNode = new Node;
        newNode->value = rand() % 100 + 1;
        newNode->left = NULL;
        newNode->right = node;
        node->left = newNode;
        node = newNode;
    }
    return node;
}
