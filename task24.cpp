#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double calculateScore(int n, double scores[]) {
    // Find the highest and lowest scores
    double maxScore = numeric_limits<double>::lowest();
    double minScore = numeric_limits<double>::max();

    for (int i = 0; i < n; ++i) {
        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
        if (scores[i] < minScore) {
            minScore = scores[i];
        }
    }

    // Calculate the sum of scores while removing one instance of max and min
    double sum = 0.0;
    bool maxRemoved = false;
    bool minRemoved = false;

    for (int i = 0; i < n; ++i) {
        if (scores[i] == maxScore && !maxRemoved) {
            maxRemoved = true;  // Remove one instance of the highest score
        } else if (scores[i] == minScore && !minRemoved) {
            minRemoved = true;  // Remove one instance of the lowest score
        } else {
            sum += scores[i];  // Add the remaining scores to the sum
        }
    }

    // Calculate the arithmetic mean of the remaining scores
    double mean = sum / (n - 2);  // n-2 because we removed two scores
    return mean;
}

int main() {
    int n;

    // Input the number of scores
    cout << "Enter the number of scores (n >= 3): ";
    cin >> n;

    // Validate input
    if (n < 3) {
        cout << "The number of scores must be at least 3!" << endl;
        return 1;
    }

    double scores[n];

    // Input the scores
    cout << "Enter the scores: ";
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    // Calculate and output the final score
    double result = calculateScore(n, scores);
    cout << "The calculated score is: " << fixed << setprecision(2) << result << endl;

    return 0;
}
