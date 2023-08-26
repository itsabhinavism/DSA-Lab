#include <iostream>

using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void representSparseMatrix(const int matrix[][MAX_COLS], int rows, int cols)
{
    int sparseMatrix[MAX_ROWS * MAX_COLS][3]; // 3-tuple format: row, column, value
    int numNonZero = 0;

    // Convert the matrix to 3-tuple format
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparseMatrix[numNonZero][0] = i;
                sparseMatrix[numNonZero][1] = j;
                sparseMatrix[numNonZero][2] = matrix[i][j];
                numNonZero++;
            }
        }
    }

    // Display the sparse matrix in 3-tuple format
    cout << "3-Tuple Format of Sparse Matrix:" << endl;
    for (int i = 0; i < numNonZero; i++)
    {
        cout << sparseMatrix[i][0] << " " << sparseMatrix[i][1] << " " << sparseMatrix[i][2] << endl;
    }
}

int main()
{
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    cout << "Enter the number of rows in the matrix: ";
    cin >> rows;
    cout << "Enter the number of columns in the matrix: ";
    cin >> cols;

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    representSparseMatrix(matrix, rows, cols);

    return 0;
}
