/**
 * @file 30827_Greedy.cpp
 * @brief 00:15:14
 * @date 2024-10-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF     1000000001

int N, K, result;
vector<ll> room;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    room.resize(K, 0);
    while (N--) {
        // <end, start>
        pair<ll, ll> meeting;
        cin >> meeting.second >> meeting.first;
        pq.push(meeting);
    }

    while (!pq.empty()) {
        pair<ll, ll> curr = pq.top();
        pq.pop();

        int minIndex = -1, minValue = INF;
        for (int i = 0; i < K; i++)
            if (room[i] < curr.second && curr.second - room[i] < minValue) {
                minIndex = i;
                minValue = curr.second - room[i];
            }
        
        if (minIndex != -1) {
            room[minIndex] = curr.first;
            result++;
        }
    }

    cout << result;

    return 0;
}