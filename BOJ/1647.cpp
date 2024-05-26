/*
최소 신장 트리 알고리즘
1. 에지 리스트로 그래프를 구현하고 유니온 파인드 배열 초기화하기: 최소 신장 트리는 에지 중심이므로 그래프를 에지 리스트로 구현한다. 유니온 파인드 배열은 사이클 처리를 위해 사용된다.
2. 그래프 데이터를 가중치 기준으로 정렬하기: 에지 리스트에 담긴 그래프 데이터를 가중치 기준으로 오름차순 정렬한다.
3. 가중치가 낮은 에지부터 연결 시도하기: 가중치가 낮은 에지부터 순서대로 연결을 시도한다. 이때 에지의 두 노드에 find 연산을 수행해서 대표 노드가 다를 시에만 연결이 성립된다.
4. 과정 3 반복하기: 연결한 에지의 개수가 N-1개가 될 때까지 과정 3을 반복한다.
5. 총 에지 비용 출력하기
*/
#include <iostream>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
using namespace std;

bool Find(vector<int>& set, int v1, int v2);
void Union(vector<int>& set, int v1, int v2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numHouses, numPaths;
    cin >> numHouses >> numPaths;

    vector<int> disjointSet(numHouses + 1);
    for (int i = 0; i <= numHouses; i++)
        disjointSet[i] = i;
    
    // tuple<weight, from, to>
    vector<tuple<int, int, int>> edgeList;
    for (int i = 0; i < numPaths; i++) {
        int weight, from, to;
        cin >> from >> to >> weight;
        edgeList.push_back(make_tuple(weight, from, to));
    }
    sort(edgeList.begin(), edgeList.end());

    int totalCost = 0;
    int maxCost = 0;
    for (int count = 0, i = 0; count < numHouses - 1; i++) {
        int weight = get<0>(edgeList[i]);
        int from = get<1>(edgeList[i]);
        int to = get<2>(edgeList[i]);

        // 아직 연결되지 않았을 경우
        if (!Find(disjointSet, from, to)) {
            Union(disjointSet, from, to);
            count++;
            totalCost += weight;
            maxCost = max(maxCost, weight);
        }
    }

    totalCost -= maxCost;

    cout << totalCost;

    return 0;
}

bool Find(vector<int>& set, int v1, int v2) {
    stack<int> v1Parents, v2Parents;

    while (v1 != set[v1]) {
        v1Parents.push(v1);
        v1 = set[v1];
    }

    while (v2 != set[v2]) {
        v2Parents.push(v2);
        v2 = set[v2];
    }

    while (!v1Parents.empty()) {
        set[v1Parents.top()] = v1;
        v1Parents.pop();
    }

    while (!v2Parents.empty()) {
        set[v2Parents.top()] = v2;
        v2Parents.pop();
    }

    if (v1 != v2)
        return false;
    else
        return true;
}

void Union(vector<int>& set, int v1, int v2) {
    while (v1 != set[v1])
        v1 = set[v1];
    
    while (v2 != set[v2])
        v2 = set[v2];

    set[v2] = v1;
}