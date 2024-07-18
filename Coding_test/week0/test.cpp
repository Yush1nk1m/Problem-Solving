#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    map<pair<int, int>, int> m;
    m[make_pair(0, 0)] = 0;

    pair<int, int> key = make_pair(0, 0);
    cout << (m.find(make_pair(0, 0)) != m.end());

    return 0;
}