#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

long long N;
long double X;
priority_queue<long double, vector<long double>, greater<long double>> pq;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        long double temp;
        cin >> temp;
        pq.push(temp);
    }

    int result = 0;

    while (!pq.empty()) {
        long double first = pq.top();
        pq.pop();

        cout << "first: " << first << endl;

        if (first >= X) {
            result++;
            continue;
        }

        if (pq.empty()) break;
        
        long double second = pq.top();
        pq.pop();

        cout << "second: " << second << endl;

        if (second >= X) {
            result++;
            continue;
        }

        long double new_container = MIN(first + second + X / 2.0, X);

        cout << "New one: " << new_container << endl;

        if (new_container >= X) {
            result++;
        }
        else {
            pq.push(new_container);
        }
    }

    cout << result;

    return 0;
}