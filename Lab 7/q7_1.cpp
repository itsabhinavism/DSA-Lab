#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = value;
        cout << value << " enqueued successfully." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
        }
        cout << "Dequeued successfully." << endl;
    }

    void traverse()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main()
{
    Queue queue;
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Traverse\n";
        cout << "4. IsEmpty\n";
        cout << "5. IsFull\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            cout << "Queue elements: ";
            queue.traverse();
            break;
        case 4:
            if (queue.isEmpty())
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Queue is not empty." << endl;
            }
            break;
        case 5:
            if (queue.isFull())
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                cout << "Queue is not full." << endl;
            }
            break;
        case 6:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);


    return 0;
}
