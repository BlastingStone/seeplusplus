#include <iostream>
#include <cstdlib>
#include <ctime>

void task5() {
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
            matrix[i][j] = rand() % 10 + 1; // Random numbers between 1 and 10 to avoid zero in product

    // Display the matrix
    std::cout << "Matrix:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    // Calculate the product of elements in odd columns
    long long productOddColumns = 1;
    for (int j = 0; j < M; j += 2) // Odd columns (0-based index, j is 0, 2, 4, ...)
        for (int i = 0; i < N; ++i)
            productOddColumns *= matrix[i][j];

    std::cout << "Product of elements in odd columns: " << productOddColumns << "\n";

    // Free allocated memory
    for (int i = 0; i < N; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    task5();
    return 0;
}
