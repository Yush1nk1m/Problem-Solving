#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int _ = 0; _ < N; _++) {
        int size;
        cin >> size;

        pq.push(size);
    }

    int answer = 0;
    while (1) {
        int first = pq.top();
        pq.pop();
        if (pq.empty()) break;

        int second = pq.top();
        pq.pop();

        answer += (first + second);
        if (pq.empty()) break;
        pq.push(first + second);
    }

    cout << answer;

    return 0;
}