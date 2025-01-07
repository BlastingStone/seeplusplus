#include <iostream>
#include <cstdlib> // For dynamic memory allocation
using namespace std;

int main() {
    int n;

    // Input the number of segments
    cout << "Enter the number of segments (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of segments!" << endl;
        return 1;
    }

    // Dynamically allocate memory for the arrays
    int* a = new int[n];
    int* b = new int[n];

    // Input the boundaries of the segments
    cout << "Enter the boundaries of the segments [a_i, b_i]:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Segment " << (i + 1) << " (a[" << i << "] and b[" << i << "]): ";
        cin >> *(a + i) >> *(b + i);
    }

    // Find the segment of maximum length
    int maxLength = -1; // Variable to store the maximum length
    int maxIndex = -1;  // Variable to store the index of the segment with maximum length

    for (int i = 0; i < n; ++i) {
        int length = *(b + i) - *(a + i); // Calculate the length of the current segment
        if (length > maxLength) {
            maxLength = length;
            maxIndex = i;
        }
    }

    // Output the result
    if (maxIndex != -1) {
        cout << "The segment of maximum length is:" << endl;
        cout << "Segment " << (maxIndex + 1) << " [a = " << *(a + maxIndex)
             << ", b = " << *(b + maxIndex) << "] with length " << maxLength << "." << endl;
    } else {
        cout << "No valid segments were found!" << endl;
    }

    // Free the dynamically allocated memory
    delete[] a;
    delete[] b;

    return 0;
}
