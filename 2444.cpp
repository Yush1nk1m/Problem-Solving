#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int i;
    for (i = 0; i < N; i++)
    {
        cout << setw(N - i - 1) << setfill(' ') << "";
        cout << setw(i * 2 + 1) << setfill('*') << "" << endl;
    }
    i -= 2;
    for (; i >= 0; i--)
    {
        cout << setw(N - i - 1) << setfill(' ') << "";
        cout << setw(i * 2 + 1) << setfill('*') << "" << endl;
    }

    return 0;
}