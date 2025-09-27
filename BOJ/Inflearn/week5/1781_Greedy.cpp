/**
 * @file 1781_Greedy.cpp
 * @brief 00:13:05
 * @date 2024-07-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Problem {
    public:
        ll deadline;
        ll ramen;
        bool operator<(const Problem& p) {
            if (deadline == p.deadline)
                return (ramen < p.ramen);
            return (deadline < p.deadline);
        }
};

ll N, result;
vector<Problem> problems;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    problems.resize(N);
    for (int i = 0; i < N; i++)
        cin >> problems[i].deadline >> problems[i].ramen;
    sort(problems.begin(), problems.end());

    for (Problem& p : problems) {
        pq.push(p.ramen);
        result += p.ramen;

        if (p.deadline < pq.size()) {
            result -= pq.top();
            pq.pop();
        }
    }

    cout << result;

    return 0;
}