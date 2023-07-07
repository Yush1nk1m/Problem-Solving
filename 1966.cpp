#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<int, int> priority_map;
vector<int> priority_status(10, 0);
queue<int> documents;
int max_priority, order, selected;

void updateMaxPriority() {
    for (int i = 9; i >= 1; i--) {
        if (priority_status[i] > 0) {
            max_priority = i;
            break;
        }
    }
}

int T, N, M, temp;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> N >> M;

        for (int doc = 0; doc < N; doc++) {
            documents.push(doc);
            cin >> temp;    // priority
            priority_map[doc] = temp;
            priority_status[temp]++;
        }

        updateMaxPriority();

        do {
            while (max_priority > priority_map[documents.front()]) {
                temp = documents.front();
                documents.pop();
                documents.push(temp);
            }

            selected = documents.front();
            documents.pop();

            order++;
            priority_status[priority_map[selected]]--;
            updateMaxPriority();

        } while (selected != M);

        cout << order << '\n';

        priority_map.clear();
        fill(priority_status.begin(), priority_status.end(), 0);
        while (!documents.empty()) documents.pop();
        order = 0;
    }
}