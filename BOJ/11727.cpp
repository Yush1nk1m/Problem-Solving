#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> cases;

int main(int argc, char* argv[]) {
    cin >> n;

    cases.resize(n + 1, 0);

    cases[1] = 1;
    cases[2] = 3;
    
    for (int i = 3; i <= n; i++)
        cases[i] = (cases[i - 1] % 10007 + cases[i - 2] * 2 % 10007) % 10007;
    
    cout << cases[n];

    return 0;
}