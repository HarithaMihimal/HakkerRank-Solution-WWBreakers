#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
        return !isspace(ch);
    }));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, ' ')) {
        tokens.push_back(token);
    }
    return tokens;
}

int flippingMatrix(vector<vector<int>> matrix) {
    int n = matrix.size() / 2;
    int maxSum = 0;

    // Traverse the top-left quadrant of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Find the maximum of four elements and add it to the maxSum
            maxSum += max(matrix[i][j], max(matrix[2 * n - 1 - i][j], max(matrix[i][2 * n - 1 - j], matrix[2 * n - 1 - i][2 * n - 1 - j])));
        }
    }

    return maxSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
