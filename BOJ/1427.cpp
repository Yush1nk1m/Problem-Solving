#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    vector<ll> numbers;
    
    ll N;
    cin >> N;

    while (N > 0)
    {
        numbers.push_back(N % 10);
        N /= 10;
    }

    sort(numbers.rbegin(), numbers.rend());

    for (vector<ll>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        cout << *iter;
    }

    return 0;
}