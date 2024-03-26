#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; i++)
        cin >> items[i].first >> items[i].second;

    vector<vector<int>> table(N + 1, vector<int>(K + 1, 0));
    for (int item = 1; item <= N; item++) {
        for (int weight = 1; weight <= K; weight++) {
            int itemWeight = items[item-1].first, itemValue = items[item-1].second;
            
            if (weight < itemWeight)
                table[item][weight] = table[item-1][weight];
            else
                table[item][weight] = max(table[item-1][weight], table[item-1][weight-itemWeight] + itemValue);
        }
    }

    cout << table[N][K];

    return 0;
}