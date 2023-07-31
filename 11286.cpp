#include <iostream>
#include <queue>
using namespace std;

struct CompareABS {
    bool operator() (int a, int b) {
        if (abs(a) == abs(b)) return (a > b);
        
        return (abs(a) > abs(b));
    }
};


int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    priority_queue<int, vector<int>, CompareABS> pq;

    int N, x;
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> x;

        if (x == 0 && !pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else if (x == 0 && pq.empty()) {
            cout << 0 << '\n';
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}