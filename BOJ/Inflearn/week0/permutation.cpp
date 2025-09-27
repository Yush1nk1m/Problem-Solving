#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> ascending = { 1, 2, 3, 4, 5 };
    vector<int> descending = { 5, 4, 3, 2, 1 };
    
    do {
        for (int number : ascending)
            cout << number << ' ';
        cout << '\n';
    } while (next_permutation(ascending.begin(), ascending.end()));

    do {
        for (int number : descending)
            cout << number << ' ';
        cout << '\n';
    } while (prev_permutation(descending.begin(), descending.end()));

    return 0;
};