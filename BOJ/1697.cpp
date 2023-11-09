#include <iostream>
#include <queue>
using namespace std;

int N, K, sec;
queue<int> locations;
vector<bool> visited;
bool is_found;

inline bool move(int location) {
    if (location > 0 && !visited[location - 1]) {
        locations.push(location - 1);
        visited[location - 1] = true;
    }
    if (location < 100000 && !visited[location + 1]) {
        locations.push(location + 1);
        visited[location + 1] = true;
    }
    if (location * 2 <= 100000 && !visited[location * 2]) {
        locations.push(location * 2);
        visited[location * 2] = true;
    }

    if (location - 1 == K || location + 1 == K || location * 2 == K) return true;
    else return false;
}

int main(int argc, char* argv[]) {
    visited.resize(100001, false);
    
    cin >> N >> K;

    if (N != K) {
        locations.push(N);
    
        while (!is_found) {
            sec++;
            int cases = locations.size();

            for (int _ = 0; _ < cases; _++) {
                is_found = move(locations.front());
                if (is_found) break;
                locations.pop();
            }
        }
    }

    cout << sec;

    return 0;
}