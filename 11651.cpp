#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<pair<int, int>> coords;

    int N, x, y;

    cin >> N;
    for (int _ = 0; _ < N; _++)
    {
        cin >> x;
        cin >> y;
        coords.push_back(pair<int, int>(y, x));
    }

    sort(coords.begin(), coords.end());

    for (int i = 0; i < N; i++)
    {
        cout << coords[i].second << " " << coords[i].first << '\n';
    }

    return 0;
}