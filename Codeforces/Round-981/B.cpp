#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                cin >> matrix[r][c];
        
        int sum = 0;
        for (int c = 0; c < n; c++) {
            int minh = 100001;
  
            for (int i = 0; i < n - c; i++)
                minh = min(minh, matrix[i][c + i]);
  
            if (minh < 0)
                sum += abs(minh);
        }

        for (int r = 1; r < n; r++) {
            int minh = 100001;
            
            for (int i = 0; i < n - r; i++)
                minh = min(minh, matrix[r + i][i]);
            
            if (minh < 0)
                sum += abs(minh);
        }

        cout << sum << '\n';
    }

    return 0;
}

//  1   1   -1  -1  3
//  -3  1   4   4   -4
//  -1  -1  3   0   -5
//  4   5   3   -3  -1
//  3   1   -3  -1  5 