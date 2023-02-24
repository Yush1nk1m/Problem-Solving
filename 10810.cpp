#include <iostream>
using namespace std;

int main()
{
    int* basket;
    int N, M;
    
    cin >> N;
    basket = new int[N + 1];
    for (int i = 1; i <= N; i++) basket[i] = 0;

    cin >> M;
    for (int _ = 0; _ < M; _++)
    {
        int i, j, k;
        cin >> i; cin >> j; cin >> k;
        for (int index = i; index <= j; index++)
        {
            basket[index] = k;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << basket[i] << " ";
    }
    
    delete[] basket;
    return 0;
}