#include <iostream>
#include <algorithm>
using namespace std;

int n[3];

int main(int argc, char* argv[]) {
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n + 3);

    cout << n[0] << ' ' << n[1] << ' ' << n[2];

    return 0;
}