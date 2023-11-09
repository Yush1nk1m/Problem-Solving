#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> coins(n);
    vector<int> result(k + 1, 0);
    result[0] = 1;

    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    for (int base = coins[0]; base <= k; base += coins[0])
        result[base] = 1;

    for (int i = 1; i < n; i++)
        for (int start = coins[i]; start <= k; start++)
            result[start] += result[start - coins[i]];

    cout << result[k];

    return 0;
}