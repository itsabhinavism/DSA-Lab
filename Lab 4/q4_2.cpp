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
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to delete a node at a given position
    void deleteNode(int position)
    {
        if (!head)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node *temp = head;

        if (position == 1)
        {
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
        }
        else
        {
            for (int i = 0; i < position - 2; i++)
            {
                temp = temp->next;
            }
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Function to print the list
    void print()
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

    list.insert(1, 1);
    list.insert(2, 2);
    list.insert(3, 3);

    cout << "List after insertions: ";
    list.print();

    list.deleteNode(2);

    cout << "List after deletion at position 2: ";
    list.print();

    return 0;
}
