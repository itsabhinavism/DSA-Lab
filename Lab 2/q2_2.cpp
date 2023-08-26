#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void countNonZeroElements(const int matrix[][MAX_SIZE], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    cout << "Number of nonzero elements: " << count << endl;
}

void displayUpperTriangular(const int matrix[][MAX_SIZE], int size)
{
    cout << "Upper triangular matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j >= i)
            {
                cout << matrix[i][j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void displayDiagonalNeighbors(const int matrix[][MAX_SIZE], int size)
{
    cout << "Elements above and below the main diagonal:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (j == i - 1)
            {
                cout << "Above: " << matrix[i][j] << " ";
            }
            else if (j == i + 1)
            {
                cout << "Below: " << matrix[i][j] << " ";
            }
            else
            {
                cout << "     ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    cout << "Enter the size of the square matrix: ";
    cin >> size;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> matrix[i][j];
        }
    }

    countNonZeroElements(matrix, size);
    cout << endl;

    displayUpperTriangular(matrix, size);
    cout << endl;

    displayDiagonalNeighbors(matrix, size);

    return 0;
}
