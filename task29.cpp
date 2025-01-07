#include <iostream>
#include <cstdlib>
#include <ctime>

void task3() {
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

    // Find the minimum element in each column
    std::cout << "Minimum in each column:\n";
    for (int j = 0; j < M; ++j) {
        int minInColumn = matrix[0][j];
        for (int i = 1; i < N; ++i)
            if (matrix[i][j] < minInColumn)
                minInColumn = matrix[i][j];
        std::cout << "Column " << j + 1 << ": " << minInColumn << "\n";
    }

    // Free allocated memory
    for (int i = 0; i < N; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task3();
    return 0;
}
