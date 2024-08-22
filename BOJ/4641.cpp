#include <bits/stdc++.h>
using namespace std;

string line;
vector<int> arr;

vector<int> Split(string input, char delim) {
    istringstream iss(input);
    string token;
    vector<int> numbers;

    while (getline(iss, token, delim))
        numbers.push_back(stoi(token));

    return numbers;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        getline(cin, line);
        if (line == "-1")
            break;

        arr = Split(line, ' ');
        sort(arr.begin(), arr.end());
        
        int cnt = 0;
        for (int i = 0; i < arr.size() - 1; i++)
            for (int j = i + 1; j < arr.size(); j++)
                if (arr[i] * 2 == arr[j])
                    cnt++;
        cout << cnt << '\n';
    }

    return 0;
}