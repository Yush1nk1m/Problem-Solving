/**
    00:06:00
 */
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> sequence;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    sequence.resize(N);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    if (next_permutation(sequence.begin(), sequence.end()))
        for (int number : sequence)
            cout << number << ' ';
    else
        cout << -1;

    return 0;
}