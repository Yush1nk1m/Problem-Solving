#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Find(vector<int>& set, int p1, int p2);
void Union(vector<int>& set, int p1, int p2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numPoints, numTurns;
    cin >> numPoints >> numTurns;

    // 집합 초기화
    vector<int> set(numPoints + 1);
    for (int i = 0; i <= numPoints; i++)
        set[i] = i;

    // 턴 초기화
    vector<pair<int, int>> turns;
    for (int _ = 0; _ < numTurns; _++) {
        int p1, p2;
        cin >> p1 >> p2;

        turns.push_back({ p1, p2 });
    }

    bool hasCycle = false;
    int turnCount = 0;
    for (pair<int, int>& turn : turns) {
        ++turnCount;

        int p1 = turn.first, p2 = turn.second;
        // 이미 같은 집합에 속해 있음 == 이으면 사이클이 완성됨
        if (Find(set, p1, p2)) {
            hasCycle = true;
            break;
        }
        
        // 같은 집합으로 포함
        Union(set, p1, p2);
    }

    if (hasCycle)
        cout << turnCount;
    else
        cout << 0;

    return 0;
}

bool Find(vector<int>& set, int p1, int p2) {
    queue<int> p1Parents, p2Parents;

    // p1이 루트가 아닌 경우 중간의 모든 노드 저장
    while (set[p1] != p1) {
        p1Parents.push(p1);
        p1 = set[p1];
    }

    // p2이 루트가 아닌 경우 중간의 모든 노드 저장
    while (set[p2] != p2) {
        p2Parents.push(p2);
        p2 = set[p2];
    }

    // p1과 p2가 같은 집합에 속해 있지 않은 경우
    if (p1 != p2) {
        // 중간 노드들의 부모를 독립적으로 갱신
        while (!p1Parents.empty()) {
            set[p1Parents.front()] = p1;
            p1Parents.pop();
        }
        
        while (!p2Parents.empty()) {
            set[p2Parents.front()] = p2;
            p2Parents.pop();
        }

        return false;
    }
    // p1과 p2가 같은 집합에 속해 있는 경우
    else {
        // 중간 노드들의 부모를 p1로 통일
        while (!p1Parents.empty()) {
            set[p1Parents.front()] = p1;
            p1Parents.pop();
        }
        
        while (!p2Parents.empty()) {
            set[p2Parents.front()] = p1;
            p2Parents.pop();
        }

        return true;
    }
}

void Union(vector<int>& set, int p1, int p2) {
    while (set[p1] != p1)
        p1 = set[p1];

    while (set[p2] != p2)
        p2 = set[p2];
    
    set[p2] = p1;
}