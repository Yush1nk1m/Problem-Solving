#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<long long> table(N + 1, 0);
    table[1] = 1;

    for (int i = 2; i <= N; i++)
        table[i] = table[i - 2] + table[i - 1];

    cout << table[N];

    return 0;
}