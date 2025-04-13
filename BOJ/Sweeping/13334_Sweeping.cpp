#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, d, res = 0;
vector<pair<int, int>> loc;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int h, o;
        cin >> h >> o;
        if (h > o) {
            int temp = h;
            h = o;
            o = temp;
        }
        loc.push_back({ o, h });
    }
    sort(loc.begin(), loc.end());

    cin >> d;

    for (int i = 0; i < n; i++) {
        int s, e;
        tie(e, s) = loc[i];

        while (pq.size() && pq.top() < e - d)
            pq.pop();
        if (e - d <= s) {
            pq.push(s);
            res = max(res, (int)pq.size());
        }
    }

    cout << res;

    return 0;
}