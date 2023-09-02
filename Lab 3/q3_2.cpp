#include <iostream>

using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int position, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a node after a given data
void insertAfterData(Node* head, int searchData, int newData) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == searchData) {
            Node* newNode = new Node;
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    cout << "Data not found in the list." << endl;
}

// Function to delete a node at a specific position
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to delete a node with a given data
void deleteData(Node*& head, int data) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Data not found in the list." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to count nodes in the linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to traverse and print the linked list
void traverseList(Node* head) {
    Node* current = head;
    cout << "Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at a specific position\n";
        cout << "2. Insert after a given data\n";
        cout << "3. Delete at a specific position\n";
        cout << "4. Delete a given data\n";
        cout << "5. Count nodes\n";
        cout << "6. Traverse the linked list\n";
        cout << "7. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int position, data;
                cout << "Enter position and data: ";
                cin >> position >> data;
                insertAtPosition(head, position, data);
                break;
            case 2:
                int searchData, newData;
                cout << "Enter data to insert after and new data: ";
                cin >> searchData >> newData;
                insertAfterData(head, searchData, newData);
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteAtPosition(head, position);
                break;
            case 4:
                int deleteDataValue;
                cout << "Enter data to delete: ";
                cin >> deleteDataValue;
                deleteData(head, deleteDataValue);
                break;
            case 5:
                cout << "Number of nodes: " << countNodes(head) << endl;
                break;
            case 6:
                traverseList(head);
                break;
            case 7:
                // Quit
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}
