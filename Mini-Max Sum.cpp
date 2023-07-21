#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
// Partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return the pivot index
}

// QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursive calls on the two sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void miniMaxSum(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    long sum1=0;
    for(int i:arr){

            sum1+=i;
        }


    cout<<sum1-arr[4]<<" "<<sum1-arr[0]<<endl;
}

    int main()
    {

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(5);

        for (int i = 0; i < 5; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        miniMaxSum(arr);

        return 0;
    }

    string ltrim(const string &str) {
        string s(str);

        s.erase(
                s.begin(),
                find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
        );

        return s;
    }

    string rtrim(const string &str) {
        string s(str);

        s.erase(
                find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
                s.end()
        );

        return s;
    }

    vector<string> split(const string &str) {
        vector<string> tokens;

        string::size_type start = 0;
        string::size_type end = 0;

        while ((end = str.find(" ", start)) != string::npos) {
            tokens.push_back(str.substr(start, end - start));

            start = end + 1;
        }

        tokens.push_back(str.substr(start));

        return tokens;
    }
