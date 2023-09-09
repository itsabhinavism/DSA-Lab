#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Node
struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a new node at the end of the list
void insert(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to search for an element in the list
int search(struct Node *head, int val)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return 1; // Element found
        }
        temp = temp->next;
    }
    return 0; // Element not found
}

// Function to sort the list in ascending order
void sort(struct Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    struct Node *current = *head;
    struct Node *min;

    while (current != NULL)
    {
        min = current;

        struct Node *temp = current->next;
        while (temp != NULL)
        {
            if (temp->data < min->data)
            {
                min = temp;
            }
            temp = temp->next;
        }

        int tempData = current->data;
        current->data = min->data;
        min->data = tempData;

        current = current->next;
    }
}

// Function to reverse the list
void reverse(struct Node **head)
{
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to print the list
void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    // Insert elements
    insert(&head, 3);
    insert(&head, 1);
    insert(&head, 5);
    insert(&head, 2);
    insert(&head, 4);

    printf("Original List: ");
    print(head);

    int searchElement = 5;
    if (search(head, searchElement))
    {
        printf("%d found in the list.\n", searchElement);
    }
    else
    {
        printf("%d not found in the list.\n", searchElement);
    }

    sort(&head);
    printf("Sorted List: ");
    print(head);

    reverse(&head);
    printf("Reversed List: ");
    print(head);

    return 0;
}
