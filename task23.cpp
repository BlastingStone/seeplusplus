#include <iostream>
using namespace std;

void sortDiagonal(int matrix[][100], int n) {
    // Step 1: Extract the main diagonal elements into a temporary array
    int diagonal[100];
    for (int i = 0; i < n; i++) {
        diagonal[i] = matrix[i][i];
    }

    // Step 2: Sort the diagonal elements using a simple Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (diagonal[j] > diagonal[j + 1]) {
                // Swap the elements
                int temp = diagonal[j];
                diagonal[j] = diagonal[j + 1];
                diagonal[j + 1] = temp;
            }
        }
    }

    // Step 3: Place the sorted elements back into the main diagonal of the matrix
    for (int i = 0; i < n; i++) {
        matrix[i][i] = diagonal[i];
    }
}

void printMatrix(int matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of the square matrix (n): ";
    cin >> n;

    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, n);

    // Sort the main diagonal
    sortDiagonal(matrix, n);

    cout << "Matrix after sorting the main diagonal:" << endl;
    printMatrix(matrix, n);

    return 0;
}
