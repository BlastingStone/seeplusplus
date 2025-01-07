#include <iostream>
#include <limits>

using namespace std;

void findSaddlePoint(int matrix[][100], int n) {
    bool found = false;

    for (int i = 0; i < n; i++) {
        // Find the maximum element in the current row
        int maxInRow = matrix[i][0];
        int colIndex = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                colIndex = j;
            }
        }

        // Check if the maximum element in the row is the minimum in its column
        bool isSaddlePoint = true;
        for (int k = 0; k < n; k++) {
            if (matrix[k][colIndex] < maxInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        // If saddle point is found, print it and exit
        if (isSaddlePoint) {
            cout << "Saddle Point found: " << maxInRow << " at position (" << i << ", " << colIndex << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No Saddle Point found in the matrix." << endl;
    }
}

int main() {
    int n;
    cout << "Enter the order of the matrix (n x n): ";
    cin >> n;

    if (n <= 0 || n > 100) {
        cout << "Invalid matrix size. Please enter a value between 1 and 100." << endl;
        return 1;
    }

    int matrix[100][100];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    findSaddlePoint(matrix, n);

    return 0;
}
