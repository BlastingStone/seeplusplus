#include <iostream>
#include <limits> // For numeric_limits
#include <cstdlib> // For abs()

using namespace std;

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array size must be greater than zero." << endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input array elements
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i); // Using pointer to access array elements
    }

    // Initialize variables to store the required values
    int maxPositive = std::numeric_limits<int>::min(); // Smallest possible integer
    int minNegative = std::numeric_limits<int>::max(); // Largest possible integer

    // Traverse the array using a pointer
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > 0 && *(arr + i) > maxPositive) {
            maxPositive = *(arr + i);
        } else if (*(arr + i) < 0 && *(arr + i) < minNegative) {
            minNegative = *(arr + i);
        }
    }

    // Determine the result
    if (maxPositive == std::numeric_limits<int>::min() && minNegative == std::numeric_limits<int>::max()) {
        cout << "The array has no positive or negative values." << endl;
    } else if (maxPositive == std::numeric_limits<int>::min()) {
        cout << "The array has no positive values. The modulus of the smallest negative value is: " << abs(minNegative) << endl;
    } else if (minNegative == std::numeric_limits<int>::max()) {
        cout << "The array has no negative values. The largest positive value is: " << maxPositive << endl;
    } else {
        int modulusOfMinNegative = abs(minNegative);

        if (maxPositive > modulusOfMinNegative) {
            cout << "The largest positive value (" << maxPositive << ") is greater than the modulus of the smallest negative value (" << modulusOfMinNegative << ")." << endl;
        } else if (maxPositive < modulusOfMinNegative) {
            cout << "The modulus of the smallest negative value (" << modulusOfMinNegative << ") is greater than the largest positive value (" << maxPositive << ")." << endl;
        } else {
            cout << "The largest positive value (" << maxPositive << ") is equal to the modulus of the smallest negative value (" << modulusOfMinNegative << ")." << endl;
        }
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
