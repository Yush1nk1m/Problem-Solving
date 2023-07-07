#include <iostream>
#include <stack>
#include <string>
using namespace std;

string line;
stack<char> parentheses;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (1) {
        bool is_balanced = true;
        getline(cin, line);
        if (line == ".") break;

        for (int i = 0; i < line.length(); i++) {
            if (line[i] == '(') parentheses.push('(');
            else if (line[i] == ')') {
                if (parentheses.empty() || parentheses.top() != '(') {
                    is_balanced = false;
                    break;
                }
                else parentheses.pop();
            }
            else if (line[i] == '[') parentheses.push('[');
            else if (line[i] == ']') {
                if (parentheses.empty() || parentheses.top() != '[') {
                    is_balanced = false;
                    break;
                }
                else parentheses.pop();
            }
        }

        if (!parentheses.empty()) is_balanced = false;

        if (is_balanced) {
            cout << "yes\n";
        }
        else cout << "no\n";

        while (!parentheses.empty()) parentheses.pop();
    }

    return 0;
}