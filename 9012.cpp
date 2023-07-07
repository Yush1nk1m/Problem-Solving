#include <iostream>
#include <stack>
using namespace std;

stack<char> parentheses;
string expression;
int N;

int main(int argc, char* argv[]) {
    cin >> N;

    for (int _ = 0; _ < N; _++) {
        while (!parentheses.empty()) parentheses.pop();
        cin >> expression;

        int i;
        for (i = 0; i < expression.length(); i++) {
            if (expression[i] == '(') parentheses.push('(');
            else {
                if (parentheses.empty()) break;
                parentheses.pop();
            }
        }

        if (i == expression.length() && parentheses.empty()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}