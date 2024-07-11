#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> v = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int number;

    while (cin >> number) {
        if (number == -1) break;

        cout << "RESULT OF FINDING NUMBER " << number << endl;
        cout << "Count based on lower_bound: " << lower_bound(v.begin(), v.end(), number) - v.begin() << endl;
        cout << "Count based on upper_bound: " << upper_bound(v.begin(), v.end(), number) - v.begin() << endl;
        cout << "------------------------------------------------------------------" << endl;
    }

    return 0;
}