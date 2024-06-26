/**
 * @file 2870_String_Sort.cpp
 * @brief 00:29:20
 * @date 2024-06-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int N;
vector<string> numbers;

inline bool compare(string n1, string n2);
inline void FindNumbers(string line);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        string line;
        cin >> line;
        FindNumbers(line);
    }

    sort(numbers.begin(), numbers.end(), compare);

    for (string number : numbers)
        cout << number << '\n';

    return 0;
}

inline bool compare(string n1, string n2) {
    if (n1.length() == n2.length()) {
        int i = 0;
        while (n1[i] == n2[i]) i++;
        
        return (i != n1.length() && n1[i] < n2[i]);
    } else return (n1.length() < n2.length());
}

inline void FindNumbers(string line) {
    int length = line.length();
    int i = 0;
    int startIdx, endIdx;
    
    while (i < length) {
        if (isdigit(line[i])) {
            startIdx = endIdx = i;
            while (endIdx < length && isdigit(line[endIdx])) endIdx++;
            
            string numstr = line.substr(startIdx, endIdx - startIdx);
            int zeroIdx = 0, numstrLen = numstr.length();
            while (zeroIdx < numstrLen && numstr[zeroIdx] == '0') zeroIdx++;
            
            if (zeroIdx == numstrLen) numstr = "0";
            else numstr = numstr.substr(zeroIdx);

            numbers.push_back(numstr);
            i = endIdx;
        } else i++;
    }
}