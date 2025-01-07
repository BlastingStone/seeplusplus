#include <iostream>
using namespace std;

// Function to rearrange the array
void rearrangeArray(int* arr, int n) {
    // Create a temporary array to store rearranged elements
    int* temp = new int[n];
    int index = 0;

    // First, copy all negative values to the temporary array
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) < 0) {
            *(temp + index) = *(arr + i);
            ++index;
        }
    }

    // Next, copy all non-negative values to the temporary array
    for (int i = 0; i < n; ++i) {
        if (*(arr + i) >= 0) {
            *(temp + index) = *(arr + i);
            ++index;
        }
    }

    // Copy the rearranged elements back to the original array
    for (int i = 0; i < n; ++i) {
        *(arr + i) = *(temp + i);
    }

    // Free the memory allocated for the temporary array
    delete[] temp;
}

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Dynamically allocate memory for the array
    int* arr = new int[n];

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> *(arr + i);
    }

    // Rearrange the array
    rearrangeArray(arr, n);

    // Output the rearranged array
    cout << "Rearranged array: ";
    for (int i = 0; i < n; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;

    // Free the memory allocated for the array
    delete[] arr;

    return 0;
}
