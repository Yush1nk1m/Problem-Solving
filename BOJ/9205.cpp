#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> src, dest;
vector<pair<int, int>> stores;
vector<bool> visited;
queue<pair<int, int>> coords;

int t, n;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    for (int _ = 0; _ < t; _++) {

        bool is_available = false;

        cin >> n;
        stores.resize(n);
        visited.resize(n, false);

        cin >> src.first >> src.second;

        for (int i = 0; i < n; i++) {
            cin >> stores[i].first >> stores[i].second;
        }

        cin >> dest.first >> dest.second;

        coords.push(src);
        while (!coords.empty()) {
            pair<int, int> coord = coords.front();
            coords.pop();

            if (abs(coord.first - dest.first) + abs(coord.second - dest.second) <= 1000) {
                is_available = true;
                break;
            }

            for (int i = 0; i < n; i++) {
                if (!visited[i] && (abs(stores[i].first - coord.first) + abs(stores[i].second - coord.second) <= 1000)) {
                    visited[i] = true;
                    coords.push(stores[i]);
                }
            }
        }

        while (!coords.empty()) coords.pop();
        stores.clear();
        visited.clear();

        if (is_available) cout << "happy\n";
        else cout << "sad\n";
    }

    return 0;
}