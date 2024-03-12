#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool visited[201][201][201];
bool recorded[201];

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> result;
    queue<tuple<int, int, int>> bfs_queue;

    visited[0][0][C] = true;
    bfs_queue.push(make_tuple(0, 0, C));
    
    while (!bfs_queue.empty()) {
        tuple<int, int, int> curr = bfs_queue.front();
        int currA = get<0>(curr), currB = get<1>(curr), currC = get<2>(curr);
        bfs_queue.pop();

        if (currA == 0 && !recorded[currC]) {
            recorded[currC] = true;
            result.push_back(currC);
        }

        // from A to the others
        int AtoB = min(currA, B - currB), AtoC = min(currA, C - currC);
        if (!visited[currA - AtoB][currB + AtoB][currC]) {
            visited[currA - AtoB][currB + AtoB][currC] = true;
            bfs_queue.push(make_tuple(currA - AtoB, currB + AtoB, currC));
        }
        if (!visited[currA - AtoC][currB][currC + AtoC]) {
            visited[currA - AtoC][currB][currC + AtoC] = true;
            bfs_queue.push(make_tuple(currA - AtoC, currB, currC + AtoC));
        }

        // from B to the others
        int BtoA = min(currB, A - currA), BtoC = min(currB, C - currC);
        if (!visited[currA + BtoA][currB - BtoA][currC]) {
            visited[currA + BtoA][currB - BtoA][currC] = true;
            bfs_queue.push(make_tuple(currA + BtoA, currB - BtoA, currC));
        }
        if (!visited[currA][currB - BtoC][currC + BtoC]) {
            visited[currA][currB - BtoC][currC + BtoC] = true;
            bfs_queue.push(make_tuple(currA, currB - BtoC, currC + BtoC));
        }

        // from C to the others
        int CtoA = min(currC, A - currA), CtoB = min(currC, B - currB);
        if (!visited[currA + CtoA][currB][currC - CtoA]) {
            visited[currA + CtoA][currB][currC - CtoA] = true;
            bfs_queue.push(make_tuple(currA + CtoA, currB, currC - CtoA));
        }
        if (!visited[currA][currB + CtoB][currC - CtoB]) {
            visited[currA][currB + CtoB][currC - CtoB] = true;
            bfs_queue.push(make_tuple(currA, currB + CtoB, currC - CtoB));
        }
    }

    sort(result.begin(), result.end());
    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << " ";

    return 0;
}