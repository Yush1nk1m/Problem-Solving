#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<bool> visited(10, false);
vector<int> pattern(10, 0);

void permutation(int depth)
{
    if (depth == M)
    {
        //cout << "depth : " << depth << endl;
        for (int i = 0; i < depth; ++i)
        {
            cout << pattern[i] << ' ';
        }
        cout << '\n';
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                pattern[depth] = i;
                permutation(depth + 1);
                visited[i] = false;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N; cin >> M;

    permutation(0);

    return 0;
}