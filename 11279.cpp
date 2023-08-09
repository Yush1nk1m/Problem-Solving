#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, less<int>> maximum_heap;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int N, x;

    cin >> N;
    for (int _ = 0; _ < N; _++) {
        cin >> x;

        if (x == 0) {
            if (maximum_heap.empty()) cout << 0 << '\n';
            else {
                cout << maximum_heap.top() << '\n';
                maximum_heap.pop();
            }
        }
        else {
            maximum_heap.push(x);
        }
    }

    return 0;
}