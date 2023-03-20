#include <iostream>
#include <vector>
#define MAX(a, b) (a > b ? a : b)
using namespace std;
typedef long long ll;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> seq(N, 0);
    for (int i = 0; i < N; ++i)
    {
        cin >> seq[i];
    }

    int res = seq[0];
    for (int i = 1; i < N; ++i)
    {
        seq[i] = MAX(seq[i-1] + seq[i], seq[i]);
        if (seq[i] > res) res = seq[i];
    }

    cout << res;

    return 0;
}