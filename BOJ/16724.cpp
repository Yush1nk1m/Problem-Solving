#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool Find(vector<vector<pair<int, int>>>& set, pair<int, int>& p1, pair<int, int>& p2);
void UnionNext(vector<vector<pair<int, int>>>& set, vector<vector<char>>& map, int r, int c);
void SetCompress(vector<vector<pair<int, int>>>& set, pair<int, int>& p);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> row >> col;
    
    vector<vector<char>> map(row, vector<char>(col));
    vector<vector<pair<int, int>>> set(row, vector<pair<int, int>>(col));
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            set[r][c] = { r, c };

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            cin >> map[r][c];

    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            UnionNext(set, map, r, c);
    
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            SetCompress(set, set[r][c]);

    int count = 0;
    for (int r = 0; r < row; r++)
        for (int c = 0; c < col; c++)
            if (set[r][c] == make_pair(r, c))
                count++;

    cout << count;

    return 0;
}

bool Find(vector<vector<pair<int, int>>>& set, pair<int, int>& p1, pair<int, int>& p2) {
    queue<pair<int, int>> p1Parents, p2Parents;

    while (set[p1.first][p1.second] != p1) {
        p1Parents.push(p1);
        p1 = set[p1.first][p1.second];
    }
    
    while (set[p2.first][p2.second] != p2) {
        p2Parents.push(p2);
        p2 = set[p2.first][p2.second];
    }

    while (!p1Parents.empty()) {
        set[p1Parents.front().first][p1Parents.front().second] = p1;
        p1Parents.pop();
    }

    while (!p2Parents.empty()) {
        set[p2Parents.front().first][p2Parents.front().second] = p2;
        p2Parents.pop();
    }
    
    if (p1 == p2)
        return true;
    else
        return false;
}

void UnionNext(vector<vector<pair<int, int>>>& set, vector<vector<char>>& map, int r, int c) {
    pair<int, int> p = { r, c };
    pair<int, int> next;
    switch (map[p.first][p.second]) {
        case 'U':
            next = { p.first - 1, p.second };
            break;
        
        case 'D':
            next = { p.first + 1, p.second };
            break;
        
        case 'L':
            next = { p.first, p.second - 1 };
            break;
        
        case 'R':
            next = { p.first, p.second + 1 };
            break;
    }

    if (!Find(set, p, next)) {
        while (p != set[p.first][p.second])
            p = set[p.first][p.second];
        
        while (next != set[next.first][next.second])
            next = set[next.first][next.second];
        
        set[next.first][next.second] = p;
    }
}

void SetCompress(vector<vector<pair<int, int>>>& set, pair<int, int>& p) {
    queue<pair<int, int>> parents;
    
    while (p != set[p.first][p.second]) {
        parents.push(p);
        p = set[p.first][p.second];
    }

    while (!parents.empty()) {
        set[parents.front().first][parents.front().second] = p;
        parents.pop();
    }
}