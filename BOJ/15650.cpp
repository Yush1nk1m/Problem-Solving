#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited(9, false);
vector<int> sequence(9, 0);
int N, M;

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
    if (_depth == M)
    {
        for (int _i = 0; _i < M; ++_i)
        {
            cout << sequence[_i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int _i = 1; _i <= N; ++_i)
        {
            if (!visited[_i] && (_depth == 0 || sequence[_depth - 1] < _i))
            {
                visited[_i] = true;
                sequence[_depth] = _i;
                dfs(_depth + 1);
                visited[_i] = false;
            }
        }
    }
}