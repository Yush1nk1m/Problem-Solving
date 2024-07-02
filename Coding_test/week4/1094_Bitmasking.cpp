#include <bits/stdc++.h>
using namespace std;

int X, cnt;

int main(int argc, char* argv[]) {
    cin >> X;
    for (int i = 0; i < 7; i++)
        if (X & (1 << i))
            cnt++;
    cout << cnt;
    return 0;
}