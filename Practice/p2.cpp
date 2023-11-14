// create double ended queue using linked list
// make a menu driven program
// 1. input restricted queue
// 1.1 insert at back
// 1.2 delete from front
// 1.3 delete from back
// 2. output restricted queue
// 2.1 insert at front
// 2.2 insert at back
// 2.3 delete from front
// 3. exit
#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *prev, *next;
};

struct Deque
{
    Node *head, *tail;
    int size;
};

int dtype = 0;

void insertfront(Deque *dq, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = dq->head;
    newNode->prev = NULL;
    if (dq->head != NULL)
        dq->head->prev = newNode;
    if (dq->tail == NULL)
        dq->tail = newNode;
    dq->head = newNode;
}

void insertback(Deque *dq, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = dq->tail;
    newNode->next = NULL;
    if (dq->tail != NULL)
        dq->tail->next = newNode;
    if (dq->head == NULL)
        dq->head = newNode;
    dq->tail = newNode;
}

int removefront(Deque *dq)
{
    Node *temp = dq->head;
    int data = temp->data;
    dq->head = temp->next;
    if (dq->head != NULL)
        dq->head->prev = NULL;
    if (dq->tail == temp)
        dq->tail = NULL;
    delete temp;
    return data;
}

int removeback(Deque *dq)
{
    Node *temp = dq->tail;
    int data = temp->data;
    dq->tail = temp->prev;
    if (dq->tail != NULL)
        dq->tail->next = NULL;
    if (dq->head == temp)
        dq->head = NULL;
    delete temp;
    return data;
}

void printDeque(Deque *dq)
{
    Node *current = dq->head;
    cout << "Deque: ";
    while (current != NULL)
    {
        current->next != NULL ? cout << current->data << " -> " : cout << current->data;
        current = current->next;
    }
    cout << "\n";
}

void operation(Deque *dq)
{
    int choice;
    cout << "\nchoice-> ";
    cin >> choice;
    if (dtype == 1)
    {
        choice >= 1 && choice <= 5 ? choice : cout << "Invalid choice\n";
    }
    if (dtype == 2)
    {
        choice >= 1 && choice <= 5 ? choice : cout << "Invalid choice\n";
        choice = choice + 5;
    }
    int element, delete;
    switch (choice)
    {
    case 6:
        cout << "Enter element: ";
        cin >> element;
        insertfront(dq, element);
        operation(dq);
        break;
    case 1:
    case 7:
        cout << "Enter element: ";
        cin >> element;
        insertback(dq, element);
        operation(dq);
        break;
    case 2:
    case 8:
        if (dq->head == NULL)
        {
            cout << "Deque is empty\n";
            operation(dq);
            break;
        }
        delete = removefront(dq);
        cout << "removed " << delete << "\n";
        operation(dq);
        break;
    case 3:
        if (dq->tail == NULL)
        {
            cout << "Deque is empty\n";
            operation(dq);
            break;
        }
        delete = removeback(dq);
        cout << "removed " << delete << "\n";
        operation(dq);
        break;
    case 4:
    case 9:
        if (dq->head == NULL)
        {
            cout << "Deque is empty\n";
            operation(dq);
            break;
        }
        printDeque(dq);
        operation(dq);
        break;
    case 5:
    case 10:
        exit(EXIT_SUCCESS);
        operation(dq);
        break;
    default:
        break;
    }
}

void inputRestricted(Deque *dq)
{
    cout << "\n***Queue type: Input Restricted***\n";
    cout << "1. Insert at back\n";
    cout << "2. Delete from front\n";
    cout << "3. Delete from back\n";
    cout << "4. Traverse\n";
    cout << "5. Exit\n";
    operation(dq);
}

void outputRestricted(Deque *dq)
{
    cout << "\n***Queue type: Output Restricted***\n";
    cout << "1. Insert at front\n";
}
 return 0;
 
 }