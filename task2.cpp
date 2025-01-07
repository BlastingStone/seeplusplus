#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

// Function to delete the i-th element from the dynamic array
void deleteElement(int*& arr, int& size, int index) {
    if (size <= 3) {
        std::cout << "Array size cannot be reduced below 3 elements." << std::endl;
        return;
    }

    // Create a new array with decreased size
    int* newArr = new int[size - 1];

    // Copy elements up to the i-th index (excluding the i-th element)
    for (int i = 0; i < index; ++i) {
        newArr[i] = arr[i];
    }

    // Copy the remaining elements after the i-th index
    for (int i = index + 1; i < size; ++i) {
        newArr[i - 1] = arr[i];
    }

    // Delete the old array
    delete[] arr;

    // Update the pointer and size
    arr = newArr;
    --size;
}

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    int n;
    do {
        std::cout << "Enter the size of the array (n < 10): ";
        std::cin >> n;
    } while (n < 3 || n >= 10); // Ensure the initial size is at least 3 and less than 10

    // Dynamically allocate the array
    int* A = new int[n];

    // Initialize the array with random positive integers
    std::cout << "Initialized array: ";
    for (int i = 0; i < n; ++i) {
        A[i] = std::rand() % 100 + 1;  // Random number between 1 and 100
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    char choice;
    do {
        std::cout << "\nChoose an operation:\n";
        std::cout << "1. Delete an element\n";
        std::cout << "2. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            int i;
            do {
                std::cout << "Enter the index of the element to delete (0-based index): ";
                std::cin >> i;
            } while (i < 0 || i >= n); // Ensure the index is valid

            // Delete the element at index i
            deleteElement(A, n, i);

            // Display the updated array
            std::cout << "Updated array: ";
            for (int j = 0; j < n; ++j) {
                std::cout << A[j] << " ";
            }
            std::cout << std::endl;
        }
    } while (choice != '2');

    // Free the allocated memory
    delete[] A;

    return 0;
}
