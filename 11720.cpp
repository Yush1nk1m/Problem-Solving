#include <iostream>
using namespace std;

int main()
{
    int sum = 0, N;
    char c;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> c;
        sum += (static_cast<int>(c) - 48);
    }

    cout << sum;
    return 0;
}