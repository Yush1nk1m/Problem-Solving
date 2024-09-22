/**
 * @file 1023_DataStructure.cpp
 * @brief 00:17:04
 * @date 2024-09-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M, curr, result;
deque<int> q;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        q.push_back(i);

    while (M--) {
        cin >> curr;

        int op2 = 0, op3 = 0;
        int i = 0;
        while (q[i] != curr) {
            i++;
            op2++;
        }
        i = 0;
        while (q[i] != curr) {
            i = (i + q.size() - 1) % q.size();
            op3++;
        }

        if (op2 < op3)
            for (int _ = 0; _ < op2; _++) {
                int n = q.front();
                q.pop_front();
                q.push_back(n);
            }
        else
            for (int _ = 0; _ < op3; _++) {
                int n = q.back();
                q.pop_back();
                q.push_front(n);
            }
        
        result += min(op2, op3);
        q.pop_front();
    }

    cout << result;

    return 0;
}