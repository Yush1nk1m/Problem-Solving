/**
 * @file 1931_Greedy.cpp
 * @brief 00:08:52
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Meeting {
    public:
        ll start;
        ll end;
        bool operator<(const Meeting& m) {
            if (end == m.end)
                return (start < m.start);
            return (end < m.end);
        }
};

int N, t, cnt;
vector<Meeting> schedule;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    schedule.resize(N);
    for (int i = 0; i < N; i++)
        cin >> schedule[i].start >> schedule[i].end;
    sort(schedule.begin(), schedule.end());

    for (Meeting& m : schedule) {
        if (m.start >= t) {
            t = m.end;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}