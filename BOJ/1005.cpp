#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int CalcTotalTime(vector<vector<int>>& graph, vector<int>& count, vector<int>& time, int dest);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, K;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> K;

        vector<vector<int>> graph(N + 1);
        vector<int> count(N + 1, 0);
        vector<int> time(N + 1);

        for (int i = 1; i <= N; i++)
            cin >> time[i];

        for (int _ = 0; _ < K; _++) {
            int from, to;
            cin >> from >> to;

            count[to]++;
            graph[from].push_back(to);
        }

        int dest;
        cin >> dest;

        cout << CalcTotalTime(graph, count, time, dest) << '\n';
    }
}

int CalcTotalTime(vector<vector<int>>& graph, vector<int>& count, vector<int>& time, int dest) {
    queue<int> structures;
    vector<int> requireTime(count.size(), 0);

    for (int structure = 1; structure < count.size(); structure++)
        if (count[structure] == 0) {
            structures.push(structure);
            requireTime[structure] = time[structure];
        }

    while (!structures.empty()) {
        int curr = structures.front();
        structures.pop();

        for (int next : graph[curr]) {
            requireTime[next] = max(requireTime[next], requireTime[curr] + time[next]);
            count[next]--;

            if (count[next] == 0)
                structures.push(next);
        }
    }

    return requireTime[dest];
}