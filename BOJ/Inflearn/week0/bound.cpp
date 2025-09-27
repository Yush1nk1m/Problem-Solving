#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> array = { 1, 2, 3, 3, 3, 4, 5 };

    auto lb = lower_bound(array.begin(), array.end(), 3);
    auto ub = upper_bound(array.begin(), array.end(), 3);

    cout << *lb << '\n';
    cout << *ub << '\n';
    cout << "number of 3: " << ub - lb << '\n';
}