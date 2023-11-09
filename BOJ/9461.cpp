#include <iostream>
using namespace std;
typedef long long ll;

ll padovan[101];

int main(int argc, char* argv[])
{
    for (int i = 0; i < 4; ++i) padovan[i] = 1;
    for (int i = 4; i <= 100; ++i)
        padovan[i] = padovan[i-3] + padovan[i-2];
    
    int T;
    ll N;
    cin >> T;

    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        cout << padovan[static_cast<int>(N)] << '\n';
    }

    return 0;
}