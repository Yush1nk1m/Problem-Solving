/**
 * @file 2109_Greedy.cpp
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * O(N^2) Greedy algorithm
 */
#include <bits/stdc++.h>
using namespace std;

class Schedule {
    public:
        int d;
        int p;
        bool operator<(const Schedule& s) {
            if (p == s.p)
                return (d < s.d);
            return (p > s.p);
        }
};

int n, pay;
bool visited[10001];
vector<Schedule> schedules;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    schedules.resize(n);
    for (int i = 0; i < n; i++)
        cin >> schedules[i].p >> schedules[i].d;
    sort(schedules.begin(), schedules.end());

    for (Schedule& s : schedules) {
        if (!visited[s.d]) {
            visited[s.d] = true;
            pay += s.p;
        } else {
            for (int i = s.d - 1; i >= 1; i--)
                if (!visited[i]) {
                    visited[i] = true;
                    pay += s.p;
                    break;
                }
        }
    }

    cout << pay;

    return 0;
}