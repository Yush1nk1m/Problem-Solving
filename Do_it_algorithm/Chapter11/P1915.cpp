#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            table[i][j] = c - '0';
        }
    
    int maxVal = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (table[i][j] == 1)
                table[i][j] = min(min(table[i-1][j], table[i][j-1]), table[i-1][j-1]) + 1;

            maxVal = max(maxVal, table[i][j]);
        }
    

    cout << (maxVal * maxVal);

    return 0;
}