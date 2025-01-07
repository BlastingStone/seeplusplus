#include <iostream>
using namespace std;

// Function to perform a cyclic left shift by 1
void cyclicLeftShift(int* arr, int n) {
    if (n <= 1) {
        return; // No shift is needed for arrays with 0 or 1 element
    }

    // Store the first element temporarily
    int firstElement = arr[0];

    // Shift all elements to the left
    for (int i = 0; i < n - 1; ++i) {
        *(arr + i) = *(arr + i + 1);
    }

    // Move the first element to the last position
    *(arr + n - 1) = firstElement;
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
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    // Input the integer k (which is > 0)
    cout << "Enter the number of left cyclic shifts (k): ";
    cin >> k;

    // Normalize k in case it's larger than array size
    k = k % n;

    // Perform k cyclic left shifts
    for (int i = 0; i < k; ++i) {
        cyclicLeftShift(arr, n);
    }

    // Output the array after the cyclic shifts
    cout << "Array after " << k << " left cyclic shift(s):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
