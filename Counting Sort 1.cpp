#include <iostream>
#include <vector>

std::vector<int> countingSort(std::vector<int> arr) {
    std::vector<int> freq(100, 0); // Initialize frequency array with 100 zeros

    for (int i : arr) {
        freq[i]++; // Increment the count for each value in the array
    }

    return freq;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> result = countingSort(arr);

    // Print the frequency array
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
