#include <iostream>
#include <string>
#include <stack>
using namespace std;

string command;
int N, option;
stack<int> Stack;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> command;

        if (command == "push") {
            cin >> option;
            Stack.push(option);
            continue;
        }

        if (command == "pop") {
            if (Stack.empty()) cout << "-1\n";
            else {
                cout << Stack.top() << '\n';
                Stack.pop();
            }
            continue;
        }

        if (command == "size") {
            cout << Stack.size() << '\n';
            continue;
        }

        if (command == "empty") {
            cout << Stack.empty() << '\n';
            continue;
        }

        if (command == "top") {
            if (Stack.empty()) cout << "-1\n";
            else cout << Stack.top() << '\n';
            continue;
        }
    }

    return 0;
}