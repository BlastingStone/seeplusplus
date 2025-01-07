#include <iostream>
#include <climits> // For INT_MAX

void findMinPositiveInEvenPlaces(int rows, int cols, int arr[100][100]) {
    int minPositive = INT_MAX;
    int minRow = -1, minCol = -1;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Check if the place is "even" (0-based indexing)
            if ((i + j) % 2 == 0 && arr[i][j] > 0 && arr[i][j] < minPositive) {
                minPositive = arr[i][j];
                minRow = i;
                minCol = j;
            }
        }
    }

    if (minPositive == INT_MAX) {
        std::cout << "No positive elements found in even places.\n";
    } else {
        std::cout << "Minimum positive element is " << minPositive
                  << " at indices (" << minRow << ", " << minCol << ").\n";
    }
}

int main() {
    int rows, cols;
    int arr[100][100];

    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;

    std::cout << "Enter the elements of the array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> arr[i][j];
        }
    }

    findMinPositiveInEvenPlaces(rows, cols, arr);

    return 0;
}
