#include <bits/stdc++.h>
using namespace std;

vector<int> arr = { 1, 2, 3, 4, 5 };
vector<int> result;

int n = 5;
int r = 3;

void Print() {
    for (int number : result)
        cout << number << ' ';
    cout << '\n';
    
    return;
}

void Combination(vector<int>& arr, int start) {
    if (result.size() == r) {
        Print();
        return;
    }

    for (int i = start; i < n; i++) {
        result.push_back(arr[i]);
        Combination(arr, i + 1);
        result.pop_back();
    }
}

int main(int argc, char* argv[]) {
    Combination(arr, 0);

    return 0;
}