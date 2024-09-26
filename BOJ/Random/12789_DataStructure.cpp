/**
 * @file 12789_DataStructure.cpp
 * @brief 00:15:55
 * @date 2024-09-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N;
queue<int> students;
stack<int> space;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        int number;
        cin >> number;
        students.push(number);
    }

    int target = 1;
    while (target <= N) {
        if (!students.empty() && students.front() == target) {
            students.pop();
            target++;
        } else if (!space.empty() && space.top() == target) {
            space.pop();
            target++;
        } else if (!students.empty()) {
            space.push(students.front());
            students.pop();
        } else {
            break;
        }
    }

    if (target > N)
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}