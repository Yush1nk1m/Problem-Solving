#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

#define INF 1000000000

static vector<tuple<int, int, int>> edgeList;

static bool BellmanFord(vector<int>& distances, int start);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    for (int _ = 0; _ < TC; _++) {
        int N, M, W;
        cin >> N >> M >> W;

        for (int m = 0; m < M; m++) {
            int start, end, time;
            cin >> start >> end >> time;

            edgeList.push_back(make_tuple(time, start, end));
            edgeList.push_back(make_tuple(time, end, start));
        }

        for (int w = 0; w < W; w++) {
            int start, end, time;
            cin >> start >> end >> time;

            edgeList.push_back(make_tuple(-time, start, end));
        }

        vector<int> distances(N + 1, INF);
        bool hasCycle = false;
        
        for (int start = 1; start <= N; start++) {
            if (distances[start] == INF) {
                BellmanFord(distances, start);
                if (BellmanFord(distances, start)) {
                    hasCycle = true;
                    break;
                }
            }
        }

        if (hasCycle)
            cout << "YES\n";
        else
            cout << "NO\n";

        edgeList.clear();
    }

    return 0;
}

static bool BellmanFord(vector<int>& distances, int start) {
    bool isChanged = false;
    int N = distances.size() - 1;
    distances[start] = 0;

    for (int _ = 0; _ < N - 1; _++) {
        for (tuple<int, int, int>& edge : edgeList) {
            int time = get<0>(edge), from = get<1>(edge), to = get<2>(edge);

            if (distances[from] != INF && distances[from] + time < distances[to]) {
                distances[to] = distances[from] + time;
                isChanged = true;
            }
        }
    }

    return isChanged;
}