#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<char, int> priority;
    priority['+'] = priority['-'] = 0;
    priority['*'] = priority['/'] = 1;

    string expression;
    cin >> expression;

    stack<char> symbols;
    for (char symbol : expression) {
        // operand
        if ('A' <= symbol && symbol <= 'Z') {
            cout << symbol;
        }
        // operator
        else if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            while (!symbols.empty() && symbols.top() != '(' && priority[symbols.top()] >= priority[symbol]) {
                cout << symbols.top();
                symbols.pop();
            }
            symbols.push(symbol);
        }
        // open parenthesis
        else if (symbol == '(') {
            symbols.push(symbol);
        }
        // close parenthesis
        else if (symbol == ')') {
            while (!symbols.empty() && symbols.top() != '(') {
                cout << symbols.top();
                symbols.pop();
            }
            symbols.pop();
        }
    }

    while (!symbols.empty()) {
        cout << symbols.top();
        symbols.pop();
    }

    return 0;
}