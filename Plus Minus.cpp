#include <iostream>
#include <iomanip> // For std::setprecision

void plusMinus(int arr[], int n) {
    int positiveCount = 0, negativeCount = 0, zeroCount = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            positiveCount++;
        else if (arr[i] < 0)
            negativeCount++;
        else
            zeroCount++;
    }

    double total = static_cast<double>(n);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << static_cast<double>(positiveCount) / total << '\n';
    std::cout << static_cast<double>(negativeCount) / total << '\n';
    std::cout << static_cast<double>(zeroCount) / total << '\n';
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    plusMinus(arr, n);

    return 0;
}
