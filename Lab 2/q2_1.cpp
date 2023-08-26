#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void insertElement(int arr[], int &n, int element, int position) {
    if (position < 0 || position > n) {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    n++;
    cout << "Element inserted successfully." << endl;
}

void deleteElement(int arr[], int &n, int position) {
    if (position < 0 || position >= n) {
        cout << "Invalid position for deletion." << endl;
        return;
    }

    for (int i = position; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    cout << "Element deleted successfully." << endl;
}

int linearSearch(const int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the element is found
        }
    }
    return -1; // Return -1 if element is not found
}

void traverseArray(const int arr[], int n) {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0; // Current number of elements in the array

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Linear search" << endl;
        cout << "4. Traverse array" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int element, position;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertElement(arr, n, element, position);
                break;
            case 2:
                cout << "Enter position to delete from: ";
                cin >> position;
                deleteElement(arr, n, position);
                break;
            case 3:
                int target;
                cout << "Enter element to search: ";
                cin >> target;
                int index = linearSearch(arr, n, target);
                if (index != -1) {
                    cout << "Element found at index " << index << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            case 4:
                traverseArray(arr, n);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
