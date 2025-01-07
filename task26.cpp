#include <iostream>
#include <limits> // For std::numeric_limits

int main() {
    int n;

    // Input the number of customers
    std::cout << "Enter the number of customers (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "The number of customers must be a positive integer.\n";
        return 1;
    }

    double t[n]; // Array to store service times for each customer
    double C[n]; // Array to store waiting times for each customer

    // Input service times for each customer
    std::cout << "Enter the service times for each customer:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "t[" << i + 1 << "] = ";
        std::cin >> t[i];

        if (t[i] < 0) {
            std::cout << "Service time cannot be negative. Please restart the program.\n";
            return 1;
        }
    }

    // Calculate the waiting times for each customer
    C[0] = t[0]; // The first customer is served immediately
    for (int i = 1; i < n; ++i) {
        C[i] = C[i - 1] + t[i];
    }

    // Output the waiting times
    std::cout << "\nWaiting times for each customer:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "C[" << i + 1 << "] = " << C[i] << "\n";
    }

    // Find the customer who required the least service time
    int minIndex = 0;
    double minTime = t[0];
    for (int i = 1; i < n; ++i) {
        if (t[i] < minTime) {
            minTime = t[i];
            minIndex = i;
        }
    }

    // Output the result
    std::cout << "\nThe customer who required the least amount of service time is customer "
              << (minIndex + 1) << " with a service time of " << minTime << ".\n";

    return 0;
}
