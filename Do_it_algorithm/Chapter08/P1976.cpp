#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void Union(vector<int>& set, int a, int b);
bool Find(vector<int>& set, int a, int b);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> set(N + 1);
    for (int i = 1; i <= N; i++)
        set[i] = i;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool isConnected;
            cin >> isConnected;

            if (isConnected)
                Union(set, i, j);
        }
    }

    vector<int> cities(M);
    for (int i = 0; i < M; i++)
        cin >> cities[i];

    bool result = true;
    for (int i = 0; i < M - 1; i++)
        if (!Find(set, cities[i], cities[i + 1]))
            result = false;

    if (result) cout << "YES";
    else cout << "NO";

    return 0;
}

void Union(vector<int>& set, int a, int b) {
    while (a != set[a])
        a = set[a];
    while (b != set[b])
        b = set[b];

    set[b] = a;
}

bool Find(vector<int>& set, int a, int b) {
    stack<int> nonRootsA, nonRootsB;

    while (a != set[a]) {
        nonRootsA.push(a);
        a = set[a];
    }

    while (b != set[b]) {
        nonRootsB.push(b);
        b = set[b];
    }

    if (a != b) {
        while (!nonRootsA.empty()) {
            int nonRoot = nonRootsA.top();
            nonRootsA.pop();
            set[nonRoot] = a;
        }
        while (!nonRootsB.empty()) {
            int nonRoot = nonRootsB.top();
            nonRootsB.pop();
            set[nonRoot] = b;
        }

        return false;
    }
    else {
        set[b] = a;
        while (!nonRootsA.empty()) {
            int nonRoot = nonRootsA.top();
            nonRootsA.pop();
            set[nonRoot] = a;
        }
        while (!nonRootsB.empty()) {
            int nonRoot = nonRootsB.top();
            nonRootsB.pop();
            set[nonRoot] = b;
        }

        return true;
    }
}