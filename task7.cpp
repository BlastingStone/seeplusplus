#include <iostream>
using namespace std;

void cyclicShiftRight(int* arr, int n) {
    if (n <= 1) return; // No need to shift if the array has 1 or fewer elements

    // Store the last element for the shift
    int lastElement = *(arr + n - 1);

    // Shift elements to the right using pointers
    for (int i = n - 1; i > 0; --i) {
        *(arr + i) = *(arr + i - 1);
    }

    // Place the last element at the first position
    *arr = lastElement;
}

int main() {
    int n, k;

    // Input the size of the array
    cout << "Enter the size of the array (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the array elements
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    // Perform the cyclic shift
    cyclicShiftRight(arr, n);

    // Output the shifted array
    cout << "Array after cyclic shift to the right by 1:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Free the allocated memory
    delete[] arr;

    return 0;
}
