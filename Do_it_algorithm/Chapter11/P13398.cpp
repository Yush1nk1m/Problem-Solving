#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000
#define REMOVED 1
#define NONREMOVED 0

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> sequence(n);
    vector<vector<int>> table(2, vector<int>(n, -INF));

    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    
    table[NONREMOVED][0] = sequence[0];
    for (int i = 1; i < n; i++) {
        table[NONREMOVED][i] = max(table[NONREMOVED][i-1] + sequence[i], sequence[i]);
        table[REMOVED][i] = max(table[NONREMOVED][i-1], table[REMOVED][i-1] + sequence[i]);
    }
    
    int maxSubtotal = -INF;
    for (int i = 0; i < n; i++) {
        maxSubtotal = max(maxSubtotal, table[NONREMOVED][i]);
        maxSubtotal = max(maxSubtotal, table[REMOVED][i]);
    }

    cout << maxSubtotal;
    
    return 0;
}