#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{
    int N;
    cin >> N;

    vector<int> tiles(N + 1, 1);
    for (int i = 2; i <= N; ++i)
    {
        tiles[i] = tiles[i-1] + tiles[i-2];
        tiles[i] %= 15746;
    }

    cout << tiles[N];

    return 0;
}