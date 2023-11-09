#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int count[10001] = { 0 };
    
    int N, temp;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        ++count[temp];
    }

    for (int i = 1; i <= 10000; ++i)
    {
        while (count[i] > 0)
        {
            cout << i << '\n';
            --count[i];
        }
    }


    return 0;
}