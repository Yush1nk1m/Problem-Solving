#include <iostream>
#include <vector>
using namespace std;

int N, count = 0;
bool table[15][15] = { false };

void dfs(int depth);
void test()
{
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            cout << table[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    
    dfs(0);

    cout << count;

    return 0;
}

void dfs(int depth)
{
    if (depth >= N)
    {
        ++count;
    }
    else
    {
        for (int i = 0; i < N; ++i)
        {
            if (!table[depth][i])
            {
                int r, c;
                
                bool before[15][15];    // save former state of the table
                for (int rowTable = 0; rowTable < N; ++rowTable)
                    for (int colTable = 0; colTable < N; ++colTable)
                        before[rowTable][colTable] = table[rowTable][colTable];

                for (r = 0; r < N; ++r) table[r][i] = true;
                for (c = 0; c < N; ++c) table[depth][c] = true;
                for (r = depth, c = i; r < N && c >= 0; ++r, --c) table[r][c] = true;   // lower left
                for (r = depth, c = i; r < N && c < N; ++r, ++c) table[r][c] = true;    // lower right
                //test();

                dfs(depth + 1);
                
                for (int rowTable = 0; rowTable < N; ++rowTable)
                    for (int colTable = 0; colTable < N; ++colTable)
                        table[rowTable][colTable] = before[rowTable][colTable];

                //test();
            }
        }
    }
}