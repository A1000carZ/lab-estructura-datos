#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* right;
};

void printNode(Node*node);
void insertRight(Node*node);
Node* insertLeft(Node*node);


int main(int argc, const char** argv) {

    Node* node = new(Node);
    node->value = 0;
    int answer;
    
    while (1)
    {
        cout << "\tMenu"<<endl;
        printNode(node);
        cout <<endl<< "\t1. Imprimir nodo actual"<<endl;
        cout << "\t2. Insertar nodo a la derecha"<<endl;
        cout << "\t3. Insertar nodo a la izquierda"<<endl;
        cout << endl <<"\tSelecciona una opcion: ";
        cin>>answer;
        switch (answer)
        {
        case 1:
            printNode(node);
            break;
        case 2:
            insertRight(node);
            break;
        case 3:
            node=insertLeft(node);
        default:
            cout << "Lo siento, no pudimos procesar su respuesta"<<endl;
            break;
        }

        system("clear");
    }
    
    return 0;
}

void printNode(Node*node){
    Node* temp;
    temp = node;
    if(node->value ==0){
        int value;
        cout << "\tVamos a inicializar el nodo"<<endl;
        cout << "\tIngresa un valor inicial: ";
        cin >> value;
        node->value = value;
        system("clear");
    }
    cout <<endl<< "\tEstatus actual"<<endl;
    cout <<"\t";
    while (temp != NULL)
    {
        cout <<"( "<< temp->value<<" )"<<"-";
        temp = temp->right;
    }
    cout <<endl;
}

void insertRight(Node*node){
    Node* temp = new(Node);
    Node* lastNode = node;
    while (lastNode->right !=NULL)
    {
        lastNode=lastNode->right;
    }    
    cout << "\tIngresa el numero a agregar: ";
    cin >> temp->value;
    temp->right= NULL;
    lastNode->right = temp;
}

Node* insertLeft(Node*node){
    Node* temp = new(Node);
    Node* firstNode = node;

    cout << "\tIngresa el numero a agregar: ";
    cin >> temp->value;
    temp->right= firstNode;

    return temp;
}

