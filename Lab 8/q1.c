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
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev, *next;
};
struct Deque
{
    struct Node *head, *tail;
    int size;
};
int dtype = 0;
void insertfront(struct Deque *dq, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = dq->head;
    newNode->prev = NULL;
    if (dq->head != NULL)
        dq->head->prev = newNode;
    if (dq->tail == NULL)
        dq->tail = newNode;
    dq->head = newNode;
}
void insertback(struct Deque *dq, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = dq->tail;
    newNode->next = NULL;
    if (dq->tail != NULL)
        dq->tail->next = newNode;
    if (dq->head == NULL)
        dq->head = newNode;
    dq->tail = newNode;
}
int removefront(struct Deque *dq)
{

    struct Node *temp = dq->head;
    int data = temp->data;
    dq->head = temp->next;
    if (dq->head != NULL)
        dq->head->prev = NULL;
    if (dq->tail == temp)
        dq->tail = NULL;
    free(temp);
    return data;
}
int removeback(struct Deque *dq)
{
    struct Node *temp = dq->tail;
    int data = temp->data;
    dq->tail = temp->prev;
    if (dq->tail != NULL)
        dq->tail->next = NULL;
    if (dq->head == temp)
        dq->head = NULL;
    free(temp);
    return data;
}
void printDeque(struct Deque *dq)
{
    struct Node *current = dq->head;
    printf("Deque: ");
    while (current != NULL)
    {
        current->next != NULL ? printf("%d -> ", current->data) : printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}
void operation(struct Deque *dq)
{
    int choice;
    printf("\nchoice-> ");
    scanf("%d", &choice);
    if (dtype == 1)
    {
        choice >= 1 && choice <= 5 ? choice : printf("Invalid choice\n");
    }
    if (dtype == 2)
    {
        choice >= 1 && choice <= 5 ? choice : printf("Invalid choice\n");
        choice = choice + 5;
    }
    int element, delete;
    switch (choice)
    {
    case 6:
        printf("Enter element: ");
        scanf("%d", &element);
        insertfront(dq, element);
        operation(dq);
        break;
    case 1:
    case 7:
        printf("Enter element: ");
        scanf("%d", &element);
        insertback(dq, element);
        operation(dq);
        break;
    case 2:
    case 8:
        if (dq->head == NULL)
        {
            printf("Deque is empty\n");
            operation(dq);
            break;
        }
        delete = removefront(dq);
        printf("removed %d\n", delete);
        operation(dq);
        break;
    case 3:
        if (dq->tail == NULL)
        {
            printf("Deque is empty\n");
            operation(dq);
            break;
        }
        delete = removeback(dq);
        printf("removed %d\n", delete);
        operation(dq);
        break;
    case 4:
    case 9:
        if (dq->head == NULL)
        {
            printf("Deque is empty\n");
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
void inputRestricted(struct Deque *dq)
{
    printf("\n***Queue type: Input Restricted***\n");
    printf("1. Insert at back\n");
    printf("2. Delete from front\n");
    printf("3. Delete from back\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
    operation(dq);
}
void outputRestricted(struct Deque *dq)
{
    printf("\n***Queue type: Output Restricted***\n");
    printf("1. Insert at front\n");
    printf("2. Insert at back\n");
    printf("3. delete at front\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");
    operation(dq);
}
void deque_type(struct Deque *dq)
{
    printf("\n***Main Menu***\n");
    printf("1. Input restricted queue\n");
    printf("2. Output restricted queue\n");
    printf("\nqueue type-> ");
    scanf("%d", &dtype);
    if (dtype == 1)
    {
        inputRestricted(dq);
    }
    else if (dtype == 2)
    {
        outputRestricted(dq);
    }
    else
    {
        printf("Invalid choice\n");
        exit(0);
    }
}

int main()
{
    struct Deque dq;
    printf("\nEnter the size of Deque-> ");
    dq.head = dq.tail = NULL;
    scanf("%d", &dq.size);
    if (dq.size <= 0)
    {
        printf("Invalid size\n");
        exit(0);
    }
    for (int i = 0; i < dq.size; i++)
    {
        int data;
        printf("Element %d-> ", i + 1);
        scanf("%d", &data);
        insertback(&dq, data);
    }
    deque_type(&dq);
    return 0;
}