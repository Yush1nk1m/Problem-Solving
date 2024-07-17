#include <bits/stdc++.h>
using namespace std;

string A, B;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B;
    if (A.length() < B.length()) {
        string temp = A;
        A = B;
        B = temp;
    }

    string zeros = "";
    for (int _ = A.length() - B.length(); _ > 0; _--)
        zeros = "0" + zeros;
    B = zeros + B;

    for (int i = 0; i < A.length(); i++)
        cout << ((A[i] - '0') + (B[i] - '0'));

    return 0;
}