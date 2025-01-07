#include <iostream>

using namespace std;

int main() {
    int n, c, d;

    // Input the size of the array
    cout << "Enter the size of the array (n): ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the elements of the array
    cout << "Enter " << n << " integers for the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);  // Using pointer to access array elements
    }

    // Input the range [c, d]
    cout << "Enter the values of c and d (c < d): ";
    cin >> c >> d;

    // Validate the input for c and d
    if (c >= d) {
        cerr << "Invalid input: c must be less than d." << endl;
        delete[] arr;  // Free the allocated memory
        return 1;
    }

    // Count the elements in the range [c, d]
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) >= c && *(arr + i) <= d) {  // Accessing elements using a pointer
            ++count;
        }
    }

    // Output the result
    cout << "Number of elements in the range [" << c << ", " << d << "]: " << count << endl;

    // Free the dynamically allocated memory
    delete[] arr;

    return 0;
}
