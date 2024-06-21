#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << accumulate(array.begin(), array.end(), 0) << '\n';

    return 0;
}