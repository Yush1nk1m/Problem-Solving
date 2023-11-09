#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> basket(N + 1, 0);
    for (int i = 1; i <= N; i++) basket[i] = i;

    for (int _ = 0; _ < M; _++)
    {
        int i, j;
        cin >> i; cin >> j;
        reverse(basket.begin() + i, basket.begin() + j + 1);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << basket[i] << " ";
    }

    return 0;
}