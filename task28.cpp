#include <iostream>
#include <cstdlib>
#include <ctime>

void task2() {
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

    // Find the maximum element in each row
    std::cout << "Maximum in each row:\n";
    for (int i = 0; i < N; ++i) {
        int maxInRow = matrix[i][0];
        for (int j = 1; j < M; ++j)
            if (matrix[i][j] > maxInRow)
                maxInRow = matrix[i][j];
        std::cout << "Row " << i + 1 << ": " << maxInRow << "\n";
    }

    // Free allocated memory
    for (int i = 0; i < N; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task2();
    return 0;
}
