#include <iostream>
#include <vector>
// Function to perform counting sort on an array of integers

std::vector<int> countingSort(std::vector<int> arr) {
    std::vector<int> freq(100, 0); // Initialize frequency array with 100 zeros
    // Calculate the frequency of each element in the input array

    for (int i : arr) {
        freq[i]++; // Increment the count for each value in the array
    }

    return freq;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
        // Read the elements of the input array

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    // Perform counting sort on the input array

    std::vector<int> result = countingSort(arr);

    // Print the frequency array (result of counting sort)
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
