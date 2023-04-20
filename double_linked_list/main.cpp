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
Node *insertRight(Node *node);
Node *insertLeft(Node *node);
void insertRandomRight(Node *node);
Node *insertRandomLeft(Node *node);
void swapNode(Node *nodeLeft,Node*nodeRight);
void shakerSort(Node *node);
void selectionSort(Node *node);
void binarySelectionSort(Node *node);
void insertionSort(Node *node);

int main()
{
    Node *firstNode = NULL;
    Node *lastNode = NULL;
    int answer;
    while (1)
    {
        if (firstNode == NULL)
        {
            firstNode = new (Node);
            int value;
            cout << "\tVamos a inicializar el nodo" << endl;
            cout << "\tIngresa un valor inicial: ";
            cin >> firstNode->value;
            firstNode->right = NULL;
            firstNode->left = NULL;
            lastNode = firstNode;
            system("clear");
        }
        cout << "\tMenu" << endl;
        printLeftToRightNode(firstNode);
        cout << endl
             << "\t1. Imprimir nodo actual de izquierda a derecha" << endl;
        cout << "\t2. Imprimir nodo actual de derecha a izquierda" << endl;
        cout << "\t3. Insertar nodo a la derecha" << endl;
        cout << "\t4. Insertar nodo a la izquierda" << endl;
        cout << "\t5. Insertar nodos aleatorios a la derecha" << endl;
        cout << "\t6. Insertar nodos aleatorios a la izquierda" << endl;
        cout << "\t7. Insertar 101 despues de un numero primo" << endl;
        cout << "\t8. Insertar N nodos en cada N numeros" << endl;
        cout << "\t9. Ordenar por shaker sort" << endl;
        cout << "\t10. Ordenar por seleccion directa" << endl;
        cout << "\t11. Ordenar por seleccion binaria" << endl;
        cout << "\t12. Ordenar por insercion directa" << endl;
        cout << endl
             << "\tSelecciona una opcion: ";
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
            firstNode = insertLeft(firstNode);
            break;
        case 5:
            insertRandomRight(firstNode);
            break;
        case 6:
            firstNode = insertRandomLeft(firstNode);
            break;
        case 9:
            shakerSort(firstNode);
        case 10:
            selectionSort(firstNode);
            break;
        case 11:
            binarySelectionSort(firstNode);
            break;
        case 12:
            insertionSort(firstNode);
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

Node *insertRight(Node *lastNode)
{
    int value;
    cout << "\tIngresa el valor del nodo: ";
    cin >> value;
    Node *newNode = new (Node);
    newNode->value = value;
    newNode->left = lastNode;
    lastNode->right = newNode;
    lastNode = newNode;
    return lastNode;
}

Node *insertLeft(Node *firstNode)
{
    int value;
    Node *newNode = new (Node);
    cout << "\tIngresa el valor del nodo: ";
    cin >> value;
    newNode->value = value;
    newNode->right = firstNode;
    firstNode->left = NULL;
    firstNode = newNode;

    return firstNode;
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

void swapNode(Node*nodeLeft,Node*nodeRight){
    int temp = nodeRight->value;
    nodeRight->value = nodeLeft->value;
    nodeLeft->value = temp;
}

void shakerSort(Node* node) {
    bool swapped = false;
    // primer nodo
    Node* firstNode = node;
    // nodo siguiente
    Node* nodeRight = node->right;
    do {
        swapped = false;
        while (firstNode != nullptr && firstNode->right != nodeRight) {
            if (firstNode->value > firstNode->right->value) {
                swapNode(firstNode, firstNode->right);
                swapped = true;
            }
            firstNode = firstNode->right;
        }
        nodeRight = firstNode;
        while (nodeRight != nullptr && nodeRight->left != nullptr && nodeRight->left != firstNode) {
            if (nodeRight->value < nodeRight->left->value) {
                swapNode(nodeRight, nodeRight->left);
                swapped = true;
            }
            nodeRight = nodeRight->left;
        }
        firstNode = nodeRight;
    } while (swapped);

    cout << "\tLa lista ha sido ordenada con éxito usando Shaker Sort" << endl;
}

void selectionSort(Node *node) {
    Node *i, *j, *minNode;
    int temp;
    for (i = node; i != NULL; i = i->right) {
        minNode = i;
        for (j = i->right; j != NULL; j = j->right) {
            if (j->value < minNode->value) {
                minNode = j;
            }
        }
        if (minNode != i) {
            temp = minNode->value;
            minNode->value = i->value;
            i->value = temp;
        }
    }
}

void binarySelectionSort(Node *node) {
    Node *i, *j, *minNode, *maxNode, *left, *right;
    int temp;
    for (i = node, j = NULL; i != j; i = left, j = maxNode) {
        for (minNode = maxNode = i; i != j; i = i->right) {
            if (i->value < minNode->value) {
                minNode = i;
            }
            if (i->value >= maxNode->value) {
                maxNode = i;
            }
        }
        temp = minNode->value;
        minNode->value = left->value;
        left->value = temp;

        if (maxNode == left) {
            maxNode = minNode;
        }

        temp = maxNode->value;
        maxNode->value = right->value;
        right->value = temp;

        left = left->right;
        right = right->left;
    }
}

void insertionSort(Node *node) {
    Node *i, *j;
    int key;
    for (i = node->right; i != NULL; i = i->right) {
        key = i->value;
        for (j = i->left; j != NULL && j->value > key; j = j->left) {
            j->right->value = j->value;
        }
        j->right->value = key;
    }
}