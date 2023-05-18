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
    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);
    myList.insert(5);

    cout << "Lista (derecha a izquierda): ";
    myList.printRightToLeft();
    cout << endl;

    cout << "Lista (izquierda a derecha): ";
    myList.printLeftToRight();
    cout << endl;

    return 0;
}
