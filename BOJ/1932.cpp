#include <iostream>
#define MAX(a, b) (a > b ? a : b)
using namespace std;

int triangle[500][500];

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            cin >> triangle[i][j];
        }
    }

    for (int i = N - 2; i >= 0; --i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            triangle[i][j] += MAX(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    cout << triangle[0][0];

    return 0;
}