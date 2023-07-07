#include <iostream>
#include <string>
#include <queue>
using namespace std;

string command;
int N, option;
queue<int> Queue;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> command;

        if (command == "push") {
            cin >> option;
            Queue.push(option);
            continue;
        }

        if (command == "pop") {
            if (Queue.empty()) cout << "-1\n";
            else {
                cout << Queue.front() << '\n';
                Queue.pop();
            }
            continue;
        }

        if (command == "size") {
            cout << Queue.size() << '\n';
            continue;
        }

        if (command == "empty") {
            cout << Queue.empty() << '\n';
            continue;
        }

        if (command == "front") {
            if (Queue.empty()) cout << "-1\n";
            else cout << Queue.front() << '\n';
            continue;
        }

        if (command == "back") {
            if (Queue.empty()) cout << "-1\n";
            else cout << Queue.back() << '\n';
            continue;
        }
    }

    return 0;
}