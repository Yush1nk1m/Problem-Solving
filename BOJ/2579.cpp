#include <iostream>
#include <vector>
#define MAX(a, b) (a > b ? a : b)
using namespace std;

vector<int> stairs(301, 0);
vector<int> sol(301, 0);

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> stairs[i];
    }
    sol[1] = stairs[1];
    sol[2] = stairs[2] + stairs[1];

    for (int i = 3; i <= N; ++i)
    {
        sol[i] = stairs[i] + MAX(sol[i-3] + stairs[i-1], sol[i-2]);
    }

    cout << sol[N];

    return 0;
}