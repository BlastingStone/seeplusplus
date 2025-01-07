#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

void task1() {
    int N, M;
    std::cout << "Enter the number of rows (N): ";
    std::cin >> N;
    std::cout << "Enter the number of columns (M): ";
    std::cin >> M;

    // Dynamically allocate memory for NxM matrix
    int** matrix = new int*[N];
    for (int i = 0; i < N; ++i)
        matrix[i] = new int[M];

    // Populate matrix with random numbers
    std::srand(std::time(0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            matrix[i][j] = rand() % 100;

    // Display the matrix
    std::cout << "Matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    // Find the minimum below the main diagonal
    int minBelowDiagonal = INT_MAX;
    for (int i = 1; i < N; ++i) // Start from row 1
        for (int j = 0; j < i; ++j) // Columns below the diagonal (j < i)
            if (matrix[i][j] < minBelowDiagonal)
                minBelowDiagonal = matrix[i][j];

    std::cout << "Minimum below the main diagonal: " << minBelowDiagonal << "\n";

    // Free allocated memory
    for (int i = 0; i < N; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task1();
    return 0;
}
