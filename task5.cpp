#include <iostream>
using namespace std;

int main() {
    int n, x;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the array elements
    cout << "Enter " << n << " sorted integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    // Input x
    cout << "Enter the value of x: ";
    cin >> x;

    // Find i such that a[i] ≤ x ≤ a[i + 1]
    int result = -1; // Default value if no such `i` is found
    for (int i = 0; i < n - 1; ++i) {
        if (*(arr + i) <= x && x <= *(arr + i + 1)) {
            result = i + 1; // Store the 1-based index
            break;
        }
    }

    // Output the result
    if (result != -1) {
        cout << "The value of i is: " << result << endl;
    } else {
        cout << "No such i exists." << endl;
    }

    // Free the allocated memory
    delete[] arr;

    return 0;
}
