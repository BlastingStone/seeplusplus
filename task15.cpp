#include <iostream>
using namespace std;

int main() {
    int n, c, d;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int *arr = new int[n];

    // Input the array elements
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i); // Use pointer to access array elements
    }

    // Input the integers c and d
    cout << "Enter the values of c and d (c < d): ";
    cin >> c >> d;

    // Initialize counters
    int inSegment = 0, outSegment = 0;

    // Iterate through the array using a pointer
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) >= c && *(arr + i) <= d) {
            ++inSegment; // Count elements in the segment [c, d]
        } else {
            ++outSegment; // Count elements not in the segment
        }
    }

    // Determine which count is greater
    if (inSegment > outSegment) {
        cout << "The number of elements in the segment [" << c << ", " << d << "] is greater.\n";
    } else if (inSegment < outSegment) {
        cout << "The number of elements not in the segment [" << c << ", " << d << "] is greater.\n";
    } else {
        cout << "The number of elements in the segment [" << c << ", " << d << "] is equal to those not in it.\n";
    }

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
