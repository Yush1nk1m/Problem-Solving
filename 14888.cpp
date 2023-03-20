#include <iostream>
#include <stack>
#include <vector>
#include <limits>
using namespace std;

int N;
int* operands;
int operators[4];
int maxResult = numeric_limits<int>::min();
int minResult = numeric_limits<int>::max();
int tempResult;

void dfs(int depth);

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N;
    operands = new int[N];
    
    for (int i = 0; i < N; ++i)
    {
        cin >> operands[i];
    }

    for (int i = 0; i < 4; ++i)
    {
        cin >> operators[i];
    }

    tempResult = operands[0];
    dfs(1);

    cout << maxResult << '\n' << minResult;

    delete[] operands;
    return 0;
}

void dfs(int depth)
{
    if (depth == N)
    {
        if (tempResult > maxResult) maxResult = tempResult;
        if (tempResult < minResult) minResult = tempResult;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            if (operators[i] > 0)
            {
                --operators[i];

                int temp = tempResult;

                switch (i)
                {
                case 0:
                    //cout << tempResult << " + " << operands[depth] << '\n';
                    tempResult += operands[depth];
                    break;
                case 1:
                    //cout << tempResult << " - " << operands[depth] << '\n';
                    tempResult -= operands[depth];
                    break;
                case 2:
                    //cout << tempResult << " * " << operands[depth] << '\n';
                    tempResult *= operands[depth];
                    break;
                case 3:
                    //cout << tempResult << " / " << operands[depth] << '\n';
                    tempResult /= operands[depth];
                    break;
                }

                dfs(depth + 1);
                
                ++operators[i];
                tempResult = temp;
            }
        }
    }
}