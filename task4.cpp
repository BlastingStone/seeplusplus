#include <iostream>

int main() {
    int n;

    // Input the size of the arrays
    std::cout << "Enter the number of segments (n): ";
    std::cin >> n;

    // Dynamically allocate memory for arrays a and b
    int* a = new int[n];
    int* b = new int[n];

    // Input the arrays
    std::cout << "Enter the elements of array a (start points of segments): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> *(a + i); // Using pointer to access array
    }

    std::cout << "Enter the elements of array b (end points of segments): ";
    for (int i = 0; i < n; ++i) {
        std::cin >> *(b + i); // Using pointer to access array
    }

    // Calculate the sum of the lengths of the segments
    int totalLength = 0;
    for (int i = 0; i < n; ++i) {
        totalLength += *(b + i) - *(a + i); // Length of each segment
    }

    // Output the result
    std::cout << "The total sum of the lengths of the segments is: " << totalLength << std::endl;

    // Free the dynamically allocated memory
    delete[] a;
    delete[] b;

    return 0;
}
