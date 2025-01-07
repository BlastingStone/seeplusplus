#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
#include <cmath>   // For abs()

using namespace std;

int main() {
    int n; // Number of elements in the array

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array must have at least one element." << endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the array elements
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    // Variables to store the smallest positive value and the largest negative value
    int smallestPositive = INT_MAX;
    int largestNegative = INT_MIN;

    // Traverse the array to find the smallest positive and largest negative values
    for (int i = 0; i < n; i++) {
        int value = *(arr + i);

        if (value > 0 && value < smallestPositive) {
            smallestPositive = value;
        } else if (value < 0 && value > largestNegative) {
            largestNegative = value;
        }
    }

    // Check if there are positive and negative values in the array
    if (smallestPositive == INT_MAX) {
        cout << "No positive values in the array." << endl;
    }
    if (largestNegative == INT_MIN) {
        cout << "No negative values in the array." << endl;
    }

    // Compare the smallest positive value with the modulus of the largest negative value
    if (smallestPositive != INT_MAX && largestNegative != INT_MIN) {
        int modulusOfLargestNegative = abs(largestNegative);

        if (smallestPositive > modulusOfLargestNegative) {
            cout << "The smallest positive value (" << smallestPositive
                 << ") is greater than the modulus of the largest negative value ("
                 << modulusOfLargestNegative << ")." << endl;
        } else if (smallestPositive < modulusOfLargestNegative) {
            cout << "The smallest positive value (" << smallestPositive
                 << ") is less than the modulus of the largest negative value ("
                 << modulusOfLargestNegative << ")." << endl;
        } else {
            cout << "The smallest positive value (" << smallestPositive
                 << ") is equal to the modulus of the largest negative value ("
                 << modulusOfLargestNegative << ")." << endl;
        }
    }

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
