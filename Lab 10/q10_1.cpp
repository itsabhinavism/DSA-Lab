#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int choice;
    cout << "Enter the sorting method: \n";
    cout << "1. Insertion Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Selection Sort\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insertionSort(arr, n);
        cout << "Sorted array: \n";
        printArray(arr, n);
        break;
    case 2:
        bubbleSort(arr, n);
        cout << "Sorted array: \n";
        printArray(arr, n);
        break;
    case 3:
        selectionSort(arr, n);
        cout << "Sorted array: \n";
        printArray(arr, n);
        break;
    default:
        cout << "Invalid input! Exiting the program.\n";
    }
    delete[] arr;
    return 0;
}
