#include <iostream>
using namespace std;

// Define the structure of a node in the circular doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class CircularDoublyLinkedList
{
private:
    Node *head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // Function to create a new node
    Node *createNode(int data)
    {
        Node *newNode = new Node{data, nullptr, nullptr};
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    // Function to insert a new element at a specific position
    void insertAtPosition(int position, int data)
    {
        Node *newNode = createNode(data);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        for (int i = 1; i < position && current->next != head; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;

        current->next->prev = newNode;
        current->next = newNode;

        if (position == 1)
        {
            head = newNode;
        }
    }

    // Function to delete an element from a specific position
    void deleteFromPosition(int position)
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head;
        for (int i = 1; i < position && current->next != head; i++)
        {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head)
        {
            head = current->next;
        }

        delete current;
    }

    // Function to traverse and print the elements of the list
    void traverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *current = head;
        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main()
{
    CircularDoublyLinkedList list;

    // Menu based operations
    int choice, position, data;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Insert element at specific position" << endl;
        cout << "2. Delete element from specific position" << endl;
        cout << "3. Traverse the list" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter position and data: ";
            cin >> position >> data;
            list.insertAtPosition(position, data);
            break;
        case 2:
            cout << "Enter position to delete: ";
            cin >> position;
            list.deleteFromPosition(position);
            break;
        case 3:
            cout << "List contents: ";
            list.traverse();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (true);

    return 0;
}
