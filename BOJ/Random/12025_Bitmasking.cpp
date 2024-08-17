/**
 * @file 12025_Bitmasking.cpp
 * @brief 00:25:04
 * @date 2024-08-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string number;
ll k, mask;
vector<int> idx;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> number >> k;
    for (int i = 0; i < number.length(); i++)
        switch (number[number.length()-i-1]) {
            case '1':
            case '2':
            case '6':
            case '7':
                idx.push_back(number.length()-i-1);
                break;
        }

    if (k > powl(2, idx.size())) {
        cout << -1;
        return 0;
    }

    k--;
    for (int i = 0; i < idx.size(); i++) {
        if ((1 << i) & k) {
            if (number[idx[i]] == '1')
                number[idx[i]] = '6';
            else if (number[idx[i]] == '2')
                number[idx[i]] = '7';
        } else {
            if (number[idx[i]] == '6')
                number[idx[i]] = '1';
            else if (number[idx[i]] == '7')
                number[idx[i]] = '2';
        }
    }

    cout << number;

    return 0;
}