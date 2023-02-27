#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void print(ll& value)
{
    cout << value << endl;
}

int main()
{
    ll T;
    cin >> T;
    vector<ll> results;

    for (ll _ = 0; _ < T; _++)
    {
        ll k, n;
        cin >> k;
        cin >> n;
        vector<vector<ll>> apartment(k + 1, vector<ll>(n + 1, 0));

        for (ll i = 0; i <= n; i++)
        {
            apartment[0][i] = i;
        }

        for (ll floor = 1; floor <= k; floor++)
        {
            ll people = 0;
            for (ll room = 1; room <= n; room++)
            {
                people += apartment[floor - 1][room];
                apartment[floor][room] = people;
            }
        }
        results.push_back(apartment[k][n]);
    }

    for_each(results.begin(), results.end(), print);
    
    return 0;
}