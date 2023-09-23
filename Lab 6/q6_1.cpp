#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack
{
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack overflow, cannot push element.\n";
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty, cannot pop element.\n";
        }
        else
        {
            top--;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
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
        cout << "c. Check if stack is empty\n";
        cout << "d. Check if stack is full\n";
        cout << "e. Display stack elements\n";
        cout << "f. Quit\n";
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
            if (stack.isFull())
            {
                cout << "Stack is full.\n";
            }
            else
            {
                cout << "Stack is not full.\n";
            }
            break;
        case 'e':
            stack.display();
            break;
        case 'f':
            cout << "Quitting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 'f');

    return 0;
}
