#include <iostream>
using namespace std;

// Define the structure for a Node
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

// Define the CircularLinkedList class
class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList() : head(NULL) {}

    // Function to insert a new node at a given position
    void insert(int val, int position)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (position == 1)
        {
            head = newNode;
        }
    }

    // Function to delete a node at a given position
    void remove(int position)
    {
        if (!head)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        for (int i = 1; i < position; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head)
        {
            prev = head;
            while (prev->next != head)
            {
                prev = prev->next;
            }
            prev->next = head->next;
            head = head->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
    }

    // Function to traverse and print the list
    void traverse()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main()
{
    CircularLinkedList list;

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Insert at position" << endl;
        cout << "2. Delete at position" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int val, position;
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Enter position: ";
            cin >> position;
            list.insert(val, position);
            cout << "Inserted " << val << " at position " << position << "." << endl;
        }
        else if (choice == 2)
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            list.remove(position);
            cout << "Deleted node at position " << position << "." << endl;
        }
        else if (choice == 3)
        {
            cout << "List elements: ";
            list.traverse();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
