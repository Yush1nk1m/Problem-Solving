#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    stack<int> stk;
    vector<int> inputs(n);
    vector<char> operations;
    bool is_valid = true;

    int curr = 1;
    stk.push(curr);
    operations.push_back('+');

    for (int i = 0; i < n; i++)
        cin >> inputs[i];
    
    for (int i = 0; i < n; i++) {
        int now = inputs[i];

        if (now <= curr) {
            if (now == stk.top()) {
                stk.pop();
                operations.push_back('-');
            } else {
                is_valid = false;
                break;
            }
        } else {
            while (now > curr) {
                stk.push(++curr);
                operations.push_back('+');
            }
            stk.pop();
            operations.push_back('-');
        }
    }

    if (is_valid) {
        for (auto it = operations.begin(); it != operations.end(); it++)
            cout << *it << '\n';
    } else {
        cout << "NO";
    }
    
    return 0;
}