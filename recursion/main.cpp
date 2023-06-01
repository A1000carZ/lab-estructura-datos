#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() {
        head = nullptr;
    }
    void insert(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertRandom(int n) {
        srand(time(nullptr)); 
        insertRandomRecursive(n);
    }

    void insertRandomRecursive(int n) {
        if (n <= 0) {
            return;
        }

        int data = rand() % 100; 
        head = insertRecursive(head, data);

        insertRandomRecursive(n - 1);
    }

    
    Node* insertRecursive(Node* node, int data) {
        if (node == nullptr) {
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            return newNode;
        }

        if (rand() % 2 == 0) {  
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = node;
            return newNode;
        }

        node->next = insertRecursive(node->next, data);
        return node;
    }

    void printRightToLeft() {
        printRightToLeftRecursive(head);
    }

    void printRightToLeftRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        printRightToLeftRecursive(node->next);
        cout << node->data << " ";
    }

    void printLeftToRight() {
        printLeftToRightRecursive(head);
    }
    void printLeftToRightRecursive(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        printLeftToRightRecursive(node->next);
    }
};

int main() {
    LinkedList myList;
    myList.insertRandom(5);
    cout << "Lista (derecha a izquierda): ";
    myList.printRightToLeft();
    cout << endl;
    cout << "Lista (izquierda a derecha): ";
    myList.printLeftToRight();
    cout << endl;
    return 0;
}
