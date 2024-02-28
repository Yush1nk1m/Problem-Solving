#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void print_window(deque<pair<int, int>>& q) {
    cout << "CURRENT WINDOW [";
    for (auto it = q.begin(); it != q.end(); it++) {
        cout << "(index: " << it->first + 1 << ", value: " << it->second << ") ->";
    }
    cout << "]\n";
}

void push(deque<pair<int, int>>& q, int index, int val) {
    while (q.size() != 0 && q.back().second > val) {
        q.pop_back();
    }
    q.push_back(make_pair(index, val));
}

int pop(deque<pair<int, int>>& q, int low_bound) {
    while (q.size() != 0 && q.front().first < low_bound) {
        q.pop_front();
    }
    return q.front().second;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    // <index, value>
    deque<pair<int, int>> window;
    vector<int> result;

    for (int i = 0; i < L - 1; i++) {
        push(window, i, numbers[i]);
        result.push_back(pop(window, 0));
    }

    for (int left = 0, right = L - 1; right < N; left++, right++) {
        push(window, right, numbers[right]);
        result.push_back(pop(window, left));
    }

    for (auto it = result.begin(); it != result.end(); it++)
        cout << *it << " ";

    return 0;
}