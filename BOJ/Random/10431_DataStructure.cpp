/**
 * @file 10431_DataStructure.cpp
 * @brief 00:09:50
 * @date 2024-09-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int P, T;
vector<int> students(20);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> P;
    while (P--) {
        cin >> T;
        for (int i = 0; i < 20; i++)
            cin >> students[i];

        int stepback = 0;
        deque<int> dq;
        dq.push_back(students[0]);

        for (int i = 1; i < 20; i++) {
            if (dq.back() < students[i])
                dq.push_back(students[i]);
            else {
                auto it = upper_bound(dq.begin(), dq.end(), students[i]);
                stepback += dq.end() - it;
                dq.insert(it, students[i]);
            }
        }

        cout << T << ' ' << stepback << '\n';
    }

    return 0;
}