#include <iostream>
using namespace std;

// Stack class
class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        if (top == 99)
        {
            cout << "Stack is almost full!" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            return true;
        }
        return false;
    }

    void push(int data)
    {
        if (!isFull())
        {
            top++;
            arr[top] = data;
            cout << data << " pushed to stack." << endl;
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            int data = arr[top];
            top--;
            cout << data << " popped from stack." << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

// Queue class
class Queue
{
private:
    int arr[100];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if (rear == 99)
        {
            cout << "Queue is almost full!" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return true;
        }
        return false;
    }

    void enqueue(int data)
    {
        if (!isFull())
        {
            rear++;
            arr[rear] = data;
            if (front == -1)
            {
                front = 0;
            }
            cout << data << " enqueued to queue." << endl;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            int data = arr[front];
            front++;
            cout << data << " dequeued from queue." << endl;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int choice, data;
    Stack s;
    Queue q;

    while (true)
    {
        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Display" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.display();
                break;

            default:
                cout << "no pudimos procesar su respuesta";
            }
        }
    }
}