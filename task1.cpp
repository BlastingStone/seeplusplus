#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Function to insert an element after the i-th position in the dynamic array
void insertElement(int*& arr, int& size, int value, int index) {
    // Create a new array with increased size
    int* newArr = new int[size + 1];

    // Copy elements up to the i-th index
    for (int i = 0; i <= index; ++i) {
        newArr[i] = arr[i];
    }

    // Insert the new element
    newArr[index + 1] = value;

    // Copy the remaining elements
    for (int i = index + 1; i < size; ++i) {
        newArr[i + 1] = arr[i];
    }

    // Delete the old array
    delete[] arr;

    // Update the pointer and size
    arr = newArr;
    ++size;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    int n;
    do {
        std::cout << "Enter the size of the array (n < 10): ";
        std::cin >> n;
    } while (n <= 0 || n >= 10);

    // Dynamically allocate the array
    int* A = new int[n];

    // Initialize the array with random positive integers
    std::cout << "Initialized array: ";
    for (int i = 0; i < n; ++i) {
        A[i] = std::rand() % 100 + 1;  // Random number between 1 and 100
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // Get the value X and position i from the user
    int X, i;
    std::cout << "Enter the value to insert (X): ";
    std::cin >> X;

    do {
        std::cout << "Enter the position after which to insert (i, 0-based index): ";
        std::cin >> i;
    } while (i < 0 || i >= n);

    // Insert the element after the i-th position
    insertElement(A, n, X, i);

    // Display the updated array
    std::cout << "Updated array: ";
    for (int j = 0; j < n; ++j) {
        std::cout << A[j] << " ";
    }
    std::cout << std::endl;

    // Free the allocated memory
    delete[] A;

    return 0;
}
