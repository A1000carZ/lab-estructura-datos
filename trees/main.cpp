// C++ Program to print binary tree in 2D
#include <iostream>

using namespace std;
#define COUNT 10

// A binary tree node
class Node
{
public:
    int value;
    Node *left, *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->value<< "\n";

    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
void crearABB(Node *, int dato);
void preOrden(Node *);
void inOrden(Node *);
void postOrden(Node *);

using namespace std;

int main()
{
    int opc, n;
    Node *raiz = new Node(0);

    while (1)
    {
        print2D(raiz);
        cout << "1. Insertar\n";
        cout << "2. Pre-Orden\n";
        cout << "3. In-Orden\n";
        cout << "4. Post-Orden\n";
        cout << "Selecciona una opciÛn: ";
        cin >> opc;
        cout << "\n";

        switch (opc)
        {
        case 1:
            if (raiz == NULL)
            {
                cout << "Ingresa el valor de la raiz: ";
                cin >> raiz->value;
            }
            else
            {
                cout << "Ingresa el valor del nodo: ";
                cin >> n;
                crearABB(raiz, n);
            }
            break;

        case 2:
            cout << "Recorrido Pre-Orden:\n";
            preOrden(raiz);
            cout << endl;
            break;

        case 3:
            cout << "Recorrido In-Orden:\n";
            inOrden(raiz);
            cout << endl;
            break;

        case 4:
            cout << "Recorrido Post-Orden:\n";
            postOrden(raiz);
            cout << endl;
            break;
        }
    }
}

void crearABB(Node *Nodo, int dato)
{
    Node *nuevo;
    if (dato < Nodo->value)
    {
        if (Nodo->left == NULL)
        {
            nuevo = new Node(0);
            Nodo->left = nuevo;
            nuevo->value = dato;
        }
        else
            crearABB(Nodo->left, dato);
    }
    else if (dato > Nodo->value)
    {
        if (Nodo->right == NULL)
        {
            nuevo = new Node(0);
            Nodo->right = nuevo;
            nuevo->value = dato;
        }
        else
            crearABB(Nodo->right, dato);
    }
    else
        cout << "El dato ya existe en el ·rbol\n";
}

void preOrden(Node *raiz)
{
    if (raiz != NULL)
    {
        cout << raiz->value << " ";
        preOrden(raiz->left);
        preOrden(raiz->right);
    }
}

void inOrden(Node *raiz)
{
    if (raiz != NULL)
    {
        inOrden(raiz->left);
        cout << raiz->value << " ";
        inOrden(raiz->right);
    }
}

void postOrden(Node *raiz)
{
    if (raiz != NULL)
    {
        postOrden(raiz->left);
        postOrden(raiz->right);
        cout << raiz->value << " ";
    }
}