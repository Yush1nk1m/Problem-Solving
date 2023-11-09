#include <iostream>
#include <vector>
using namespace std;

void swap(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int N, M;
    cin >> N;
    cin >> M;

    vector<int> basket(N + 1, 0);
    for (int i = 0; i <= N; i++) basket[i] = i;

    for (int _ = 0; _ < M; _++)
    {
        int i, j;
        cin >> i; cin >> j;
        swap(basket[i], basket[j]);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << basket[i] << " ";
    }

    return 0;
}