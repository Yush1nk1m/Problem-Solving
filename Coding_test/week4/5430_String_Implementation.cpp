/**
 * @file 5430_String_Implementation.cpp
 * @brief 00:29:08
 * @date 2024-07-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int T, N;
string func, arrstr;
deque<string> arr;

inline void Print(deque<string>& arr);
inline void PrintReverse(deque<string>& arr);
inline deque<string> Split(string input, char delim);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> func;
        cin >> N;
        cin >> arrstr;

        arr = Split(arrstr.substr(1, arrstr.length() - 2), ',');
        bool err = false, revert = false;
        for (char command : func) {
            if (command == 'R') {
                revert = !revert;
            } else {
                if (arr.size() == 0)
                    err = true;
                else if (revert)
                    arr.pop_back();
                else
                    arr.pop_front();
            }
        }
        
        if (err) cout << "error\n";
        else if (revert) PrintReverse(arr);
        else Print(arr);
    }

    return 0;
}

inline deque<string> Split(string input, char delim) {
    istringstream iss(input);
    string token;
    deque<string> tokens;

    while (getline(iss, token, delim))
        tokens.push_back(token);

    return tokens;
}

inline void Print(deque<string>& arr) {
    cout << "[";
    if (arr.size() != 0)
        cout << arr[0];
    for (int i = 1; i < arr.size(); i++)
        cout << "," << arr[i];
    cout << "]\n";
}

inline void PrintReverse(deque<string>& arr) {
    cout << "[";
    if (arr.size() != 0)
        cout << arr[arr.size() - 1];
    for (int i = arr.size() - 2; i >= 0; i--)
        cout << "," << arr[i];
    cout << "]\n";
}