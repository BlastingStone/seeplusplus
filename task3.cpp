#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function to insert an element before the i-th index
void insertElement(int*& array, int& size, int value, int index) {
    if (index < 0 || index > size) {
        std::cerr << "Error: Invalid index." << std::endl;
        return;
    }

    // Allocate a new array with increased size
    int* newArray = new int[size + 1];

    // Copy elements up to the index where the new value will be inserted
    for (int i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }

    // Insert the new value
    newArray[index] = value;

    // Copy remaining elements from the original array
    for (int i = index; i < size; ++i) {
        newArray[i + 1] = array[i];
    }

    // Free the memory of the old array
    delete[] array;

    // Update the pointer and size
    array = newArray;
    ++size;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Declare and initialize variables
    int n;
    do {
        std::cout << "Enter the size of the array (n < 10): ";
        std::cin >> n;
    } while (n <= 0 || n >= 10);

    // Dynamically allocate an array of size n
    int* A = new int[n];

    // Initialize the array with random positive integers
    for (int i = 0; i < n; ++i) {
        A[i] = std::rand() % 100 + 1; // Random numbers between 1 and 100
    }

    // Display the initialized array
    std::cout << "Initial array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // Add a new element before the i-th element
    int value, index;
    std::cout << "Enter the value to insert: ";
    std::cin >> value;
    std::cout << "Enter the index (0-based) before which to insert the value: ";
    std::cin >> index;

    insertElement(A, n, value, index);

    // Display the updated array
    std::cout << "Updated array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    // Free allocated memory
    delete[] A;

    return 0;
}
