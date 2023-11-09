#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

stack<int> numbers;
vector<bool> pushed;
queue<char> instructions;
int n, number, prev_number, next_push = 1;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    pushed.resize(n + 1, false);

    for (int _ = 0; _ < n; _++) {
        cin >> number;
        
        if (prev_number < number) {
            for (int i = next_push; i <= number; i++) {
                if (pushed[i] == false) {
                    instructions.push('+');
                    numbers.push(i);
                    pushed[i] = true;
                }
            }
            next_push = number + 1;

            instructions.push('-');
            numbers.pop();
        }

        if (prev_number > number) {
            if (numbers.top() != number) {
                cout << "NO";
                return 0;
            }

            instructions.push('-');
            numbers.pop();
        }

        prev_number = number;
    }

    while (!instructions.empty()) {
        cout << instructions.front() << '\n';
        instructions.pop();
    }

    return 0;
}