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
void ShakerSort(Node *p);
void selectionSort(Node *node);
void binarySelectionSort(Node *node);
void insertionSort(Node *node);
void bubbleSort(Node *node);


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
        cout << "\t10. Ordenar por bubble sort" << endl;
        cout << "\t11. Ordenar por seleccion directa" << endl;
        cout << "\t12. Ordenar por seleccion binaria" << endl;
        cout << "\t13. Ordenar por insercion directa" << endl;
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
            bubbleSort(firstNode);
        case 10:
            ShakerSort(firstNode);
        case 11:
            selectionSort(firstNode);
            break;
        case 12:
            binarySelectionSort(firstNode);
            break;
        case 13:
            insertionSort(firstNode);
            break;
        default:
            cout << "Lo siento, no pudimos procesar su respuesta" << endl;
            break;
        }
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
    cout << "\tIngresa la cleftidad de nodos a insertar: ";
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
    cout << "\tIngresa la cleftidad de nodos que deseas insertar: ";
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

void bubbleSort(Node*node){
    Node *aux, *aux2,*aux3=node;
	int total=0, i, j, temp;
	aux = node;
	cout << "Lista:" << "\n";
	while (aux != NULL)
	{
		cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";
	aux = node;
	char band;
	while (aux != NULL)  //total de nodos
	{
		total++;
		aux = aux->right;
	}

	for (i = 1; i < total; i++)
	{
		cout << "Paso" << i << "----------------------------------------------------------------" << "\n";
		aux = node;
		aux2 = aux->right;

		for (j = 1; j < total; j++)  //total de comparacion
		{
			if (aux->value > aux2->value)
			{
				temp = aux->value;
				aux->value = aux2->value;
				aux2->value = temp;
				band = 'V';
			}
			else
			{
				band = 'F';
			}
			cout << "\tComparacion\tArreglo\n";
			cout << "\t-----------\t------------------------\n";
			cout << "\t[" << aux2->value << ">" << aux->value << "]\t" << band << "\t";
			while (aux3 != NULL)
			{
				cout << aux3->value << " ";
				aux3 = aux3->right;
			}
			cout << "\n";
			aux = aux2;
			aux2 = aux2->right;
			aux3 = node;
		}
	}
}

void ShakerSort(Node* p)
{
	Node* aux, *aux2,*aux3,*aux4,*aux5;
	int i, direc, band, pasos, total=0,inicio,valor,valor2;
	aux5 = NULL;
	aux3 = 0;
	aux = p;
	aux4 = p;
	pasos = 1;
	direc = 1;
	inicio = 0;
	cout << "Lista:" << "\n";
	while (aux != NULL)
	{
		cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";

	aux = p;
	while (aux != NULL)  //total de nodos
	{
		total++;
		if (aux->right == NULL)
		{
			aux5 = aux;
		}
		aux = aux->right;

	}
	do
	{
		band = 0;
		switch (direc)
		{
		case 1:
			cout << "Paso " << pasos << "\n";
			cout << "Derecha a Izquierda\n";
			aux2 = aux5;
			aux = aux5->left;
			for (i = total - 1; i >= inicio + 1; i--)
			{
				if (aux2->value < aux->value)
				{
					cout << aux2->value << "<" << aux->value;
					cout << " V " << band << "\n";
					valor = aux2->value;
					aux2->value = aux->value;
					aux->value = valor;
					aux = aux->left;
					aux2 = aux2->left;
					band++;
				}
				else
				{
					cout << aux2->value << "<" << aux->value;
					cout << " F " << band << "\n";
					aux = aux->left;
					aux2 = aux2->left;
				}
			}
			direc = 2;
			inicio++;
			break;
		case 2:
			aux = p;
			for (i = 0; i <= inicio; i++)
			{
				aux = aux->right;
			}
			aux2 = aux4;
			aux = aux4->right;
			cout << "Izquierda a Derecha\n";
			for (i = inicio + 1; i <= total; i++)
			{
				if (aux2->value > aux->value)
				{
					band++;
					cout << aux2->value << ">" << aux->value;
					cout << " V " << band << "\n";
					valor = aux2->value;
					aux2->value = aux->value;
					aux->value = valor;
					aux = aux->right;
					aux2 = aux2->right;
				}
				else
				{
					cout << aux2->value << "<" << aux->value;
					cout << " F " << band << "\n";
					aux = aux->right;
					aux2 = aux2->right;
				}
			}
			pasos++;
			direc = 1;
			cout << "\n";
			break;
		}
	} while (band != 0);
}

void selectionSort(Node *node) {
    Node* aux = NULL, * aux2 = NULL, * aux3 = NULL, * aux4 = NULL;
	int valor = 0, valor2 = 0, i = 0, j = 0, k = 0, inicio = 0, total = 0;
	aux = node;
	while (aux != NULL)
	{
		cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";
	aux = node;
	while (aux != NULL)  //total de nodos
	{
		total++;
		aux = aux->right;
	}
	aux = node;
	aux3 = node;
	aux2 = node->right;
	valor = aux->value;
	while (aux->right != NULL)
	{
		for (i = inicio; i <= total-2; i++)
		{
			if (aux2->value < aux3->value)
			{
				valor2 = aux2->value;
				aux3 = aux2;
				aux2 = aux2->right;
			}
			else
			{
				aux2 = aux2->right;
			}
		}
		cout << "Valor minimo: " << valor << "\n";
		cout << "valor maximo: " << valor2 << "\n";
		aux->value = valor2;
		aux3->value = valor;
		aux = aux->right;
		aux2 = aux->right;
		aux3 = aux;
		inicio++;
		valor = aux->value;
		if (aux->right != NULL)
		{
			valor2 = aux2->value;
		}
		aux4 = node;
		while (aux4 != NULL)
		{
			cout << aux4->value << " ";
			aux4 = aux4->right;
		}
		cout << "\n";
	}
}

void binarySelectionSort(Node *node) {
    int i = 0, j = 0, k = 0, l=0, contador=0, valor = 0, valor2 = 0, valor3 = 0, total = 0, inicio = 0;
	Node* aux = NULL, * aux2 = NULL, * aux3 = NULL, * aux4 = NULL, * aux5 = NULL;
	char flag = NULL;
	aux = node;
	while (aux != NULL)
	{
		cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";
	aux = node;
	while (aux != NULL)  //total de nodos
	{
		total++;
		aux = aux->right;
	}
	aux = node->right;
	aux2 = node;
	aux3 = aux;
	for (i = inicio; i <= total - 2; i++)
	{
		cout << "Pasada " << i + 1 << ":" << "\n";

		for (j = k; j >= 0; j--)
		{
			cout << aux->value << "<" << aux2->value << " ";
			if (aux->value < aux2->value)
			{
				valor = aux->value;
				flag = 'V';
				contador++;
				if (aux2->left != NULL)
				{
					aux2 = aux2->left;
					cout << "-->" << flag << "\t";
					aux4 = node;
					while (aux4 != NULL)
					{
						cout << aux4->value << " ";
						aux4 = aux4->right;
					}
					cout << "\n";
				}
				else
				{
					aux2 = aux->left;
					cout << "-->" << flag << "\t";
					aux4 = node;
					while (aux4 != NULL)
					{
						cout << aux4->value << " ";
						aux4 = aux4->right;
					}
					cout << "\n";
					break;
				}
			}
		}
		aux3 = aux;
		for (l = 0; l <= contador-1; l++)
		{
			aux->value = aux2->value;
			if (aux2->left != NULL)
			{
				aux2 = aux2->left;
				aux = aux->left;
			}
		}
		aux2->value = valor;
		k++;
		aux = aux3->right;
		aux2 = aux3;
	}
}

void insertionSort(Node *node) {
    int i=0, j=0, k=0, valor=0, valor2=0,valor3=0,total=0,inicio=0;
	Node* aux=NULL,*aux2 = NULL,*aux3 = NULL,*aux4 = NULL,*aux5 = NULL;
	char flag = NULL;
	aux = node;
	while (aux != NULL)
	{
		cout << aux->value << " ";
		aux = aux->right;
	}
	cout << "\n";
	aux = node;
	while (aux != NULL)  //total de nodos
	{
		total++;
		aux = aux->right;
	}
	aux = node->right;
	aux2 = node;
	aux3 = aux;
	for (i = inicio; i <= total-2; i++)
	{
		cout << "Pasada " << i+1 << ":"<<"\n";

		for (j = k; j >= 0; j--)
		{
			cout << aux->value << "<" << aux2->value<<" ";
			if (aux->value < aux2->value)
			{
				flag = 'V';
				valor = aux->value;
				valor2 = aux2->value;
				aux2->value = valor;
				aux->value = valor2;
				if (aux2->left == NULL)
				{
					if (aux3->right != NULL)
					{
						aux = aux3->right;
						aux3 = aux;
						aux2 = aux->left;
					}
				}
				else
				{
					aux = aux->left;
					aux2 = aux2->left;
				}
			}
			else
			{
				flag = 'F';
				if (aux2->left == NULL)
				{
					if (aux3->right != NULL)
					{
						aux = aux3->right;
						aux3 = aux;
						aux2 = aux->left;
					}
				}
				else
				{
					aux2 = aux2->left;
				}
			}
			cout <<"-->"<< flag << "\t";
			aux4 = node;
			while (aux4 != NULL)
			{
				cout << aux4->value << " ";
				aux4 = aux4->right;
			}
			cout << "\n";
		}
		k++;
	}
}