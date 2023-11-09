#include <iostream>
#include <vector>
using namespace std;

int T, n, i;
vector<int> cases;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cases.resize(11);
    
    cin >> T;

    cases[i++] = 0;
    cases[i++] = 1;
    cases[i++] = 2;
    cases[i++] = 4;

    for (; i <= 10; i++) {
        cases[i] = cases[i - 1] + cases[i - 2] + cases[i - 3];
    }

    for (int _ = 0; _ < T; _++) {
        cin >> n;
        cout << cases[n] << '\n';
    }

    return 0;
}