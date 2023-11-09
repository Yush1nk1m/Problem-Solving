#include <iostream>
#include <string>
#include <deque>
using namespace std;

string command;
int N, option;
deque<int> Deque;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> command;

        if (command == "push_front") {
            cin >> option;
            Deque.push_front(option);
            continue;
        }

        if (command == "push_back") {
            cin >> option;
            Deque.push_back(option);
            continue;
        }

        if (command == "pop_front") {
            if (Deque.empty()) cout << "-1\n";
            else {
                cout << Deque.front() << '\n';
                Deque.pop_front();
            }
            continue;
        }

        if (command == "pop_back") {
            if (Deque.empty()) cout << "-1\n";
            else {
                cout << Deque.back() << '\n';
                Deque.pop_back();
            }
            continue;
        }

        if (command == "size") {
            cout << Deque.size() << '\n';
            continue;
        }

        if (command == "empty") {
            cout << Deque.empty() << '\n';
            continue;
        }

        if (command == "front") {
            if (Deque.empty()) cout << "-1\n";
            else cout << Deque.front() << '\n';
            continue;
        }

        if (command == "back") {
            if (Deque.empty()) cout << "-1\n";
            else cout << Deque.back() << '\n';
            continue;
        }
    }

    return 0;
}