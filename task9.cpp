#include <iostream>
using namespace std;

int main() {
    int n, c, d;

    // Input size of the array
    cout << "Enter the size of the array (n): ";
    cin >> n;

    // Input the range [c, d]
    cout << "Enter the range values c and d (c < d): ";
    cin >> c >> d;

    if (c >= d) {
        cout << "Error: c should be less than d." << endl;
        return 1;
    }

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input array elements
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i); // Using pointer to access array elements
    }

    // Count elements not in the range [c, d]
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) < c || *(arr + i) > d) {
            ++count;
        }
    }

    // Output the result
    cout << "Number of elements not in the range [" << c << ", " << d << "]: " << count << endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
