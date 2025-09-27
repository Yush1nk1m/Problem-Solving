/**
 * @file 1269_BinarySearch.cpp
 * @brief 00:04:56
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int numA, numB, cnt;
vector<int> A, B;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numA >> numB;
    A.resize(numA);
    B.resize(numB);

    for (int i = 0; i < numA; i++)
        cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; i < numB; i++)
        cin >> B[i];
    sort(B.begin(), B.end());

    for (int number : A)
        cnt += (number != *(lower_bound(B.begin(), B.end(), number)));

    for (int number : B)
        cnt += (number != *(lower_bound(A.begin(), A.end(), number)));

    cout << cnt;

    return 0;
}