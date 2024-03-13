#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define UNION 0
#define FIND 1

void Union(vector<int>& set, int a, int b);
bool Find(vector<int>& set, int a, int b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> set(n + 1);
    for (int i = 0; i <= n; i++)
        set[i] = i;
    
    for (int _ = 0; _ < m; _++) {
        int operation;
        cin >> operation;

        if (operation == UNION) {
            int a, b;
            cin >> a >> b;
            Union(set, a, b);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << (Find(set, a, b) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}

void Union(vector<int>& set, int a, int b) {
    while (a != set[a])
        a = set[a];
    while (b != set[b])
        b = set[b];
    
    set[a] = set[b];
}

bool Find(vector<int>& set, int a, int b) {
    stack<int> nonRootsA, nonRootsB;

    int rootB = b;
    while (rootB != set[rootB]) {
        nonRootsB.push(rootB);
        rootB = set[rootB];
    }

    int rootA = a;
    while (rootA != set[rootA]) {
        nonRootsA.push(rootA);
        rootA = set[rootA];
    }

    if (rootA == rootB) {
        while (!nonRootsB.empty()) {
            int node = nonRootsB.top();
            nonRootsB.pop();
            set[node] = rootA;
        }
        while (!nonRootsA.empty()) {
            int node = nonRootsA.top();
            nonRootsA.pop();
            set[node] = rootA;
        }

        return true;
    }
    else {
        while (!nonRootsB.empty()) {
            int node = nonRootsB.top();
            nonRootsB.pop();
            set[node] = rootB;
        }
        while (!nonRootsA.empty()) {
            int node = nonRootsA.top();
            nonRootsA.pop();
            set[node] = rootA;
        }

        return false;
    }
}