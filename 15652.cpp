#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq(9, 0);

inline void dfs(int _depth);

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    dfs(0);

    return 0;
}

inline void dfs(int _depth)
{
    if (_depth >= M)
    {
        for (int _i = 0; _i < _depth; ++_i)
        {
            cout << seq[_i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int _i = 1; _i <= N; _i++)
        {
            if (_depth == 0 || seq[_depth - 1] <= _i)
            {
                seq[_depth] = _i;
                dfs(_depth + 1);
            }
        }
    }
}