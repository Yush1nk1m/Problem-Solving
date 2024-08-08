#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<ll> numbers;
vector<ll> origin;

void DFS(int depth, ll prior);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    for (ll number : numbers) {
        origin.push_back(number);
        DFS(1, number);
        origin.pop_back();
    }

    return 0;
}

void DFS(int depth, ll prior) {
    if (depth == N) {
        for (ll number : origin)
            cout << number << ' ';
        exit(0);
    }

    if (prior % 3 == 0 && *lower_bound(numbers.begin(), numbers.end(), prior / 3) == prior / 3) {
        origin.push_back(prior / 3);
        DFS(depth + 1, prior / 3);
        origin.pop_back();
    }
    if (*lower_bound(numbers.begin(), numbers.end(), prior * 2) == prior * 2) {
        origin.push_back(prior * 2);
        DFS(depth + 1, prior * 2);
        origin.pop_back();
    }
}