#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> array = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };

    cout << "MIN: " << *(min_element(array.begin(), array.end())) << '\n';
    cout << "MAX: " << *(max_element(array.begin(), array.end())) << '\n';

    return 0;
}