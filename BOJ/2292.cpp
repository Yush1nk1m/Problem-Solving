#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll N;
    cin >> N;

    ll count = 1;
    ll room = 1;
    while (room < N)
    {
        count++;
        room += (count * 6 - 6);
    }
    cout << count;

    return 0;
}