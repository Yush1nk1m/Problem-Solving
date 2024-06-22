#include <bits/stdc++.h>
using namespace std;

void Print(vector<int>& array) {
    for (int number : array) cout << number << ' ';
    cout << '\n';
}

int main(int argc, char* argv[]) {
    vector<int> array = { 1, 2, 3, 4, 5 };

    Print(array);

    string input;
    while (getline(cin, input)) {
        if (input == "exit") break;

        rotate(array.begin(), array.begin() + 1, array.end());
        Print(array);
    }

    while (getline(cin, input)) {
        if (input == "exit") break;

        rotate(array.rbegin(), array.rbegin() + 1, array.rend());
        Print(array);
    }
    return 0;
}