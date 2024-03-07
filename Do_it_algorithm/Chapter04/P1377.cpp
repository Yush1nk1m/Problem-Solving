#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // <value, index>
    vector<pair<int, int>> array(N);
    for (int i = 0; i < N; i++) {
        cin >> array[i].first;
        array[i].second = i;
    }

    sort(array.begin(), array.end());

    int max_move = 0;
    for (int i = 0; i < N; i++)
        if (array[i].second - i > max_move)
            max_move = array[i].second - i;
    
    cout << max_move + 1;

    return 0;
}