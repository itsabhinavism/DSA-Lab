#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop element.\n";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack elements: ";
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack stack;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "a. Push\n";
        cout << "b. Pop\n";
        cout << "c. IsEmpty\n";
        cout << "d. Display stack elements\n";
        cout << "e. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            stack.push(val);
            break;
        case 'b':
            stack.pop();
            break;
        case 'c':
            if (stack.isEmpty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;
        case 'd':
            stack.display();
            break;
        case 'e':
            cout << "Quitting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'e');

    return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop element.\n";
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack elements: ";
            Node *temp = top;
            while (temp != nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack stack;
    char choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "a. Push\n";
        cout << "b. Pop\n";
        cout << "c. IsEmpty\n";
        cout << "d. Display stack elements\n";
        cout << "e. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            int val;
            cout << "Enter value to push: ";
            cin >> val;
            stack.push(val);
            break;
        case 'b':
            stack.pop();
            break;
        case 'c':
            if (stack.isEmpty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;
        case 'd':
            stack.display();
            break;
        case 'e':
            cout << "Quitting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'e');

    return 0;
}
