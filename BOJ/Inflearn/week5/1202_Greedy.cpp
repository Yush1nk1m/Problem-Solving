/**
 * @file 1202_Greedy.cpp
 * @brief 00:44:55
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

class Jew {
    public:
        ll M;
        ll V;
        bool operator<(const Jew& j) {
            if (M == j.M)
                return (V < j.V);
            return (M < j.M);
        }
};

int N, K;
ll result;
vector<Jew> jews;
vector<ll> bags;
priority_queue<ll, vector<ll>, less<ll>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    jews.resize(N);
    bags.resize(K);

    for (int i = 0; i < N; i++)
        cin >> jews[i].M >> jews[i].V;
    for (int i = 0; i < K; i++)
        cin >> bags[i];
    
    sort(jews.begin(), jews.end());
    sort(bags.begin(), bags.end());

    int ji = 0;
    for (int bag : bags) {
        while (ji < jews.size() && jews[ji].M <= bag)
            pq.push(jews[ji++].V);
        
        if (pq.size()) {
            result += pq.top();
            pq.pop();
        }
    }

    cout << result;

    return 0;
}