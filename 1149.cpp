#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> table(1000, vector<int>(3, 0));

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> table[i][0] >> table[i][1] >> table[i][2];
    }

    for (int i = 1; i < N; ++i)
    {
        table[i][0] += (table[i - 1][1] < table[i - 1][2] ? table[i - 1][1] : table[i - 1][2]);
        table[i][1] += (table[i - 1][0] < table[i - 1][2] ? table[i - 1][0] : table[i - 1][2]);
        table[i][2] += (table[i - 1][0] < table[i - 1][1] ? table[i - 1][0] : table[i - 1][1]);
    }

    int res = table[N - 1][0];
    if (table[N - 1][1] < res) res = table[N - 1][1];
    if (table[N - 1][2] < res) res = table[N - 1][2];

    cout << res;

    return 0;
}