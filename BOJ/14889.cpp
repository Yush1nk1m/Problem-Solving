#include <iostream>
#include <limits>
using namespace std;

int N;
int stats[21][21];
int start[11];
int link[11];
bool visited[21] = { false };
int difference = numeric_limits<int>::max();

void dfs(int depth);

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;

    for (int r = 1; r <= N; ++r)
    {
        for (int c = 1; c <= N; ++c)
        {
            cin >> stats[r][c];
        }
    }

    dfs(0);
    cout << difference;

    return 0;
}

void dfs(int depth)
{
    if (depth == N / 2)
    {
        int sumStart = 0, sumLink = 0;

        for (int i = 1, idx = 0; i <= N; ++i)
        {
            if (!visited[i]) link[idx++] = i;
        }

        for (int i = 0; i < depth; ++i)
        {
            for (int j = 0; j < depth; ++j)
            {
                sumStart += stats[start[i]][start[j]];
                sumLink += stats[link[i]][link[j]];
            }
        }

        //cout << "difference: " << abs(sumStart - sumLink) << '\n';

        if (abs(sumStart - sumLink) < difference)
            difference = abs(sumStart - sumLink);
    }
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                bool isAvail = true;
                for (int j = i + 1; j <= N; ++j)
                    if (visited[j]) isAvail = false;

                if (isAvail)
                {
                    visited[i] = true;
                    start[depth] = i;
                    dfs(depth + 1);
                    visited[i] = false;
                }
            }
        }
    }
}