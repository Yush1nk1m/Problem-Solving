#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> lines;
vector<int> lis, indices;
stack<int> stk;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    lines.resize(n);
    for (int i = 0; i < n; i++)
        cin >> lines[i].first >> lines[i].second;
    sort(lines.begin(), lines.end());
    
    lis.push_back(lines[0].second);
    indices.push_back(0);
    for (int i = 1; i < n; i++) {
        int idx = lower_bound(lis.begin(), lis.end(), lines[i].second) - lis.begin();
        if (idx == lis.size()) {
            lis.push_back(lines[i].second);
            indices.push_back(lis.size() - 1);
        } else {
            if (lines[i].second < lis[idx]) {
                lis[idx] = lines[i].second;
            }
            indices.push_back(idx);
        }
    }

    for (int i = n - 1, j = lis.size() - 1; i >= 0; i--) {
        if (indices[i] == j)
            j--;
        else
            stk.push(lines[i].first);
    }

    cout << stk.size() << '\n';
    while (!stk.empty()) {
        cout << stk.top() << '\n';
        stk.pop();
    }

    return 0;
}