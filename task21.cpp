#include <iostream>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Function to sort negative elements of a column in ascending order
void sortColumnAscending(int matrix[ROWS][COLS], int col, int rows) {
    // Collect negative elements in a temporary array
    int temp[ROWS], count = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] < 0) {
            temp[count++] = matrix[i][col];
        }
    }

    // Sort the temporary array in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }

    // Replace negative elements in the column with sorted values
    count = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] < 0) {
            matrix[i][col] = temp[count++];
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {3, -1, 4, 1},
        {-5, 9, 2, -6},
        {5, -3, -2, 7},
        {8, -9, 10, -4}
    };

    cout << "Original Matrix:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Sort each column
    for (int j = 0; j < COLS; j++) {
        sortColumnAscending(matrix, j, ROWS);
    }

    cout << "\nMatrix after sorting negative elements in each column:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
