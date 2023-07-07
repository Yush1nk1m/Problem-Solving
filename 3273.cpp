#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, l, r, sum, result;
vector<int> sequence;

int main(int argc, char* argv[]) {
    cin >> n;
    sequence.resize(n);

    for (int i = 0; i < n; i++)
        cin >> sequence[i];

    cin >> x;

    sort(sequence.begin(), sequence.end());
    
    l = 0;
    r = n - 1;
    
    while (l >= 0 && r < n && l < r) {
        sum = sequence[l] + sequence[r];
        if (sum == x) {
            result++;
            l++;
        }
        else if (sum > x) {
            r--;
        }
        else {  // (sum < x)
            l++;
        }
    }

    cout << result;

    return 0;
}