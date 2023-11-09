#include <iostream>
#include <stack>
using namespace std;

stack<int> numbers;
int K, temp, result;

int main(int argc, char* argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> K;
    for (int _ = 0; _ < K; _++) {
        cin >> temp;
        if (temp != 0) numbers.push(temp);
        else numbers.pop();
    }

    while (!numbers.empty()) {
        result += numbers.top();
        numbers.pop();
    }

    cout << result;

    return 0;
}