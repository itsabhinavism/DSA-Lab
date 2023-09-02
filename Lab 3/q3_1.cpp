#include <iostream>
#include <vector>

using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int numRows;
    int numCols;
    int numElements;
    vector<Element> elements;
};

SparseMatrix transposeSparseMatrix(const SparseMatrix& inputMatrix) {
    SparseMatrix transposedMatrix;
    transposedMatrix.numRows = inputMatrix.numCols;
    transposedMatrix.numCols = inputMatrix.numRows;
    transposedMatrix.numElements = inputMatrix.numElements;
    
    for (int i = 0; i < inputMatrix.numCols; ++i) {
        for (int j = 0; j < inputMatrix.numElements; ++j) {
            if (inputMatrix.elements[j].col == i) {
                Element transposedElement;
                transposedElement.row = inputMatrix.elements[j].col;
                transposedElement.col = inputMatrix.elements[j].row;
                transposedElement.value = inputMatrix.elements[j].value;
                transposedMatrix.elements.push_back(transposedElement);
            }
        }
    }
    
    return transposedMatrix;
}

int main() {
    SparseMatrix inputMatrix;
    
    // Input the dimensions and non-zero elements of the matrix
    cout << "Enter the number of rows: ";
    cin >> inputMatrix.numRows;
    cout << "Enter the number of columns: ";
    cin >> inputMatrix.numCols;
    cout << "Enter the number of non-zero elements: ";
    cin >> inputMatrix.numElements;
    
    for (int i = 0; i < inputMatrix.numElements; ++i) {
        Element element;
        cout << "Enter element " << i + 1 << " (row, column, value): ";
        cin >> element.row >> element.col >> element.value;
        inputMatrix.elements.push_back(element);
    }
    
    SparseMatrix transposedMatrix = transposeSparseMatrix(inputMatrix);
    
    // Output the transposed matrix
    cout << "\nTransposed Matrix (in 3-tuple format):\n";
    cout << "Rows: " << transposedMatrix.numRows << ", Columns: " << transposedMatrix.numCols << endl;
    for (const Element& element : transposedMatrix.elements) {
        cout << element.row << " " << element.col << " " << element.value << endl;
    }
    
    return 0;
}
