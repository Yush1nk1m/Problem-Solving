#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> group;

int N, x, y;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    
    for (int _ = 0; _ < N; _++) {
        cin >> x >> y;
        group.push_back({x, y});
    }

    for (int men = 0; men < N; men++) {
        int rank = 0;

        for (int other = 0; other < N; other++) {
            if (group[men].first < group[other].first && group[men].second < group[other].second)
                rank++;
        }

        cout << rank + 1 << ' ';
    }

    return 0;
}