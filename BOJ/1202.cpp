#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> jewelries(N);
    vector<int> bags(K);
    long long int totalValue = 0;

    for (int i = 0; i < N; i++)
        cin >> jewelries[i].first >> jewelries[i].second;

    for (int i = 0; i < K; i++)
        cin >> bags[i];
    
    sort(jewelries.begin(), jewelries.end());
    sort(bags.begin(), bags.end());

    int idx = 0;
    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < K; i++) {
        while (idx < N && jewelries[idx].first <= bags[i])
            pq.push(jewelries[idx++].second);
        
        if (pq.empty())
            continue;

        totalValue += pq.top();
        pq.pop();
    }

    cout << totalValue;

    return 0;
}