#include <iostream>
#include <algorithm>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Function to sort positive elements of a row in descending order
void sortRowDescending(int row[], int cols) {
    // Collect positive elements in a temporary array
    int temp[COLS], count = 0;
    for (int i = 0; i < cols; i++) {
        if (row[i] > 0) {
            temp[count++] = row[i];
        }
    }

    // Sort the temporary array in descending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (temp[j] < temp[j + 1]) {
                swap(temp[j], temp[j + 1]);
            }
        }
    }

    // Replace positive elements in the row with sorted values
    count = 0;
    for (int i = 0; i < cols; i++) {
        if (row[i] > 0) {
            row[i] = temp[count++];
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

    // Sort each row
    for (int i = 0; i < ROWS; i++) {
        sortRowDescending(matrix[i], COLS);
    }

    cout << "\nMatrix after sorting positive elements in each row:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
