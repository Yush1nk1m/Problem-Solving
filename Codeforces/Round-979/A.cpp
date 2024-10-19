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
        
        vector<int> a(n);
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int maxElement = *max_element(a.begin(), a.end());
        int minElement = *min_element(a.begin(), a.end());

        int sum = (n - 1) * (maxElement - minElement);

        cout << sum << '\n';
    }

    return 0;
}