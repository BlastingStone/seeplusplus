#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n;

    // Ask the user for the size of the array (n < 10)
    std::cout << "Enter the size of the array (n < 10): ";
    std::cin >> n;

    // Validate input
    if (n <= 0 || n >= 10) {
        std::cerr << "Invalid input! n must be greater than 0 and less than 10." << std::endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* A = new int[n];

    // Seed the random number generator
    std::srand(std::time(0));

    // Fill the array with random positive integers (1 to 100)
    for (int i = 0; i < n; ++i) {
        A[i] = std::rand() % 100 + 1; // Random number between 1 and 100
    }

    // Display the array elements and their memory addresses using pointers
    std::cout << "Array elements and their memory addresses:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "A[" << i << "] = " << *(A + i) 
                  << " at address " << (A + i) << std::endl;
    }

    // Free the dynamically allocated memory
    delete[] A;

    return 0;
}
