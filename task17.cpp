#include <iostream>
#include <cmath> // For std::abs()

using namespace std;

void findLargestModulusElement(int** matrix, int n, int& maxRow, int& maxCol) {
    double maxModulus = 0; // To store the largest modulus
    maxRow = 0;
    maxCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double currentModulus = abs(matrix[i][j]); // Modulus is the absolute value
            if (currentModulus > maxModulus) {
                maxModulus = currentModulus;
                maxRow = i;
                maxCol = j;
            }
        }
    }
}

void createReducedMatrix(int** originalMatrix, int n, int rowToRemove, int colToRemove, int** reducedMatrix) {
    int newRow = 0;
    for (int i = 0; i < n; i++) {
        if (i == rowToRemove) continue; // Skip the row to remove

        int newCol = 0;
        for (int j = 0; j < n; j++) {
            if (j == colToRemove) continue; // Skip the column to remove

            reducedMatrix[newRow][newCol] = originalMatrix[i][j];
            newCol++;
        }
        newRow++;
    }
}

int main() {
    int n;

    // Input the size of the square matrix
    cout << "Enter the order of the square matrix: ";
    cin >> n;

    // Dynamically allocate memory for the square matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Input the elements of the matrix
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find the element with the largest modulus and its position
    int maxRow, maxCol;
    findLargestModulusElement(matrix, n, maxRow, maxCol);

    cout << "Element with the largest modulus: " << matrix[maxRow][maxCol] << " at position (" << maxRow << ", " << maxCol << ")" << endl;

    // Dynamically allocate memory for the reduced matrix of size (n-1) x (n-1)
    int** reducedMatrix = new int*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        reducedMatrix[i] = new int[n - 1];
    }

    // Create the reduced matrix
    createReducedMatrix(matrix, n, maxRow, maxCol, reducedMatrix);

    // Output the reduced matrix
    cout << "Reduced matrix:" << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << reducedMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n - 1; i++) {
        delete[] reducedMatrix[i];
    }
    delete[] reducedMatrix;

    return 0;
}
