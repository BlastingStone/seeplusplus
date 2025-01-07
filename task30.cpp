#include <iostream>
#include <cstdlib>
#include <ctime>

void task4() {
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

    // Calculate the sum of elements in even rows
    int sumEvenRows = 0;
    for (int i = 1; i < N; i += 2) // Even rows (1-based index)
        for (int j = 0; j < M; ++j)
            sumEvenRows += matrix[i][j];

    std::cout << "Sum of elements in even rows: " << sumEvenRows << "\n";

    // Free allocated memory
    for (int i = 0; i < N; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task4();
    return 0;
}
