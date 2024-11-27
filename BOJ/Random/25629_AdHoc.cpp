#include <bits/stdc++.h>
using namespace std;

int N, odd = 0, even = 0;
vector<int> A;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        int number;
        cin >> number;

        if (number % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << (odd == even || odd - 1 == even);

    return 0;
}