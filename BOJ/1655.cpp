#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> minQueue;
    priority_queue<int, vector<int>, less<int>> maxQueue;

    int N;
    cin >> N;

    for (int iter = 1; iter <= N; iter++) {
        int number;
        cin >> number;

        if (iter % 2 != 0)
            maxQueue.push(number);
        else
            minQueue.push(number);
        
        while (!maxQueue.empty() && !minQueue.empty() && maxQueue.top() > minQueue.top()) {
            maxQueue.push(minQueue.top());
            minQueue.push(maxQueue.top());
            maxQueue.pop(); minQueue.pop();
        }

        cout << maxQueue.top() << '\n';
    }

    return 0;
}