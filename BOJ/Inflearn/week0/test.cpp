#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    int N;
    cout << "Target number: ";
    cin >> N;

    cout << "The number of numbers below " << N << ": ";
    cout << (upper_bound(v.begin(), v.end(), N) - v.begin()) << endl;

    return 0;
}