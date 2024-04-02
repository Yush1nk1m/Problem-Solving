#include <iostream>
#include <stack>
#include <string>
using namespace std;

string input, pattern;
// <value, pattern index>
stack<pair<char, int>> stk;
static int bombIndex;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input >> pattern;

    int p = pattern.size();
    bombIndex = p - 1;
    for (int i = input.size() - 1; i >= 0; i--) {
        if (input[i] == pattern[bombIndex]) {
            stk.push({input[i], bombIndex});
            bombIndex--;
        } else {
            bombIndex = p - 1;
            if (input[i] == pattern[bombIndex]) {
                stk.push({input[i], bombIndex});
                bombIndex--;
            } else {
                stk.push({input[i], -1});
            }
        }

        // explosion
        if (bombIndex < 0) {
            for (int _ = 0; _ < p; _++) {
                stk.pop();
            }
            
            if (stk.empty() || stk.top().second == -1) {
                bombIndex = p - 1;
            } else {
                bombIndex = stk.top().second - 1;
            }
        }
    }

    if (stk.empty())
        cout << "FRULA";
    else
        while (!stk.empty()) {
            cout << stk.top().first;
            stk.pop();
        }

    return 0;
}