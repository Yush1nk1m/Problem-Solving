#include <iostream>
#include <vector>
using namespace std;

#define INF 100000

static int minScore = INF;
static vector<vector<int>> graph;
static vector<int> candidates;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numMember;
    cin >> numMember;

    graph.resize(numMember + 1, vector<int>(numMember + 1, INF));
    for (int i = 1; i <= numMember; i++)
        graph[i][i] = 0;
    
    int v1, v2;
    while (cin >> v1 >> v2) {
        if (v1 == -1 && v2 == -1)
            break;
        
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    for (int mid = 1; mid <= numMember; mid++)
        for (int start = 1; start <= numMember; start++)
            for (int end = 1; end <= numMember; end++)
                graph[start][end] = min(graph[start][end], graph[start][mid] + graph[mid][end]);

    for (int start = 1; start <= numMember; start++) {
        int score = 0;
        for (int end = 1; end <= numMember; end++) {
            score = max(score, graph[start][end]);
        }

        if (score < minScore) {
            candidates.clear();
            candidates.push_back(start);
            minScore = score;
        } else if (score == minScore) {
            candidates.push_back(start);
        }
    }

    cout << minScore << ' ' << candidates.size() << '\n';
    for (int candidate : candidates)
        cout << candidate << ' ';

    return 0;
}