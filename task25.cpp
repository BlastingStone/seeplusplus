#include <iostream>
#include <limits> // For numeric limits

using namespace std;

int main() {
    int n; // Number of elements in the sequence
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. The sequence must have at least one element." << endl;
        return 1;
    }

    double *arr = new double[n]; // Dynamically allocate array for the sequence
    cout << "Enter the elements of the sequence:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Find the smallest and largest numbers
    double smallest = numeric_limits<double>::max();
    double largest = numeric_limits<double>::lowest();

    for (int i = 0; i < n; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Compute the square of the smallest and largest numbers
    double squareOfSmallest = smallest * smallest;
    double squareOfLargest = largest * largest;

    // Modify the sequence
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0) {
            arr[i] *= squareOfSmallest; // Multiply by the square of the smallest number
        } else {
            arr[i] *= squareOfLargest; // Multiply by the square of the largest number
        }
    }

    // Output the modified sequence
    cout << "Modified sequence:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free the allocated memory
    return 0;
}
