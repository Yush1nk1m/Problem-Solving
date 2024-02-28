#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> NGE(N, -1);
    // <index, value>
    stack<pair<int, int>> numbers;

    for (int index = 0; index < N; index++) {
        int curr;
        cin >> curr;

        while (!numbers.empty() && numbers.top().second < curr) {
            int index = numbers.top().first;
            NGE[index] = curr;
            numbers.pop();
        }

        numbers.push({index, curr});
    }

    for (auto it = NGE.begin(); it != NGE.end(); it++)
        cout << *it << " ";
    
    return 0;
}