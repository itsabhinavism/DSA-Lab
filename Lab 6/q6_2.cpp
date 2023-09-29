#include<iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Element " << value << " pushed onto the stack.\n";
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        cout << "Element " << poppedValue << " popped from the stack.\n";
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "a. Push\n";
        cout << "b. Pop\n";
        cout << "c. IsEmpty\n";
        cout << "d. Display\n";
        cout << "e. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'a': {
                int value;
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }
            case 'b': {
                stack.pop();
                break;
            }
            case 'c': {
                if (stack.isEmpty()) {
                    cout << "Stack is empty.\n";
                } else {
                    cout << "Stack is not empty.\n";
                }
                break;
            }
            case 'd': {
                stack.display();
                break;
            }
            case 'e': {
                cout << "Exiting program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 'e');

    return 0;
}
