#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<ll> coords(N, 0);
    vector<ll> uniqueCoords(N, 0);
    map<ll, int> reduced;

    for (int i = 0; i < N; i++)
    {
        cin >> coords[i];
        uniqueCoords[i] = coords[i];
    }

    sort(uniqueCoords.begin(), uniqueCoords.end());
    uniqueCoords.erase(unique(uniqueCoords.begin(), uniqueCoords.end()), uniqueCoords.end());

    int i = 0;
    vector<ll>::iterator iter;
    for (i = 0, iter = uniqueCoords.begin(); iter < uniqueCoords.end(); i++, iter++)
    {
        reduced.insert(pair<ll, int>(*iter, i));
    }

    for (i = 0; i < N; i++)
    {
        cout << reduced[coords[i]] << " ";
    }
    
    return 0;
}