#include <iostream>
#include <limits> // For numeric limits like INT_MIN and INT_MAX

using namespace std;

void swapElements(int** matrix, int rows, int cols) {
    int maxNegative = INT_MIN;
    int minPositive = INT_MAX;
    int maxNegRow = -1, maxNegCol = -1;
    int minPosRow = -1, minPosCol = -1;

    // Traverse the matrix to find the maximum negative and minimum positive elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < 0 && matrix[i][j] > maxNegative) {
                maxNegative = matrix[i][j];
                maxNegRow = i;
                maxNegCol = j;
            }
            if (matrix[i][j] > 0 && matrix[i][j] < minPositive) {
                minPositive = matrix[i][j];
                minPosRow = i;
                minPosCol = j;
            }
        }
    }

    // Check if both a negative and positive element were found
    if (maxNegRow != -1 && minPosRow != -1) {
        // Swap the maximum negative and minimum positive elements
        int temp = matrix[maxNegRow][maxNegCol];
        matrix[maxNegRow][maxNegCol] = matrix[minPosRow][minPosCol];
        matrix[minPosRow][minPosCol] = temp;
    } else {
        cout << "No valid swap can be performed (matrix may lack negative or positive elements)." << endl;
    }
}

int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate the matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Input the matrix elements
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Perform the swap operation
    swapElements(matrix, rows, cols);

    // Output the modified matrix
    cout << "Modified matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
