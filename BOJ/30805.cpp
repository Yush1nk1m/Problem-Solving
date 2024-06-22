#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> A, B;
vector<int> res;

// If there's common value, return true
inline bool findCommonMax() {
    vector<bool> aHash(101, false);
    vector<bool> bHash(101, false);

    for (int number : A)
        aHash[number] = true;
    for (int number : B)
        bHash[number] = true;

    for (int number = 100; number >= 1; number--)
        if (aHash[number] && bHash[number]) {
            res.push_back(number);
            
            int aIdx = 0, bIdx = 0;
            while (A[aIdx] != number) aIdx++;
            while (B[bIdx] != number) bIdx++;

            A.erase(A.begin(), A.begin() + aIdx + 1);
            B.erase(B.begin(), B.begin() + bIdx + 1);
            
            return true;
        }
    
    return false;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        A.push_back(n);
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;
        B.push_back(n);
    }

    while (findCommonMax())
        ;
    
    cout << res.size() << '\n';
    for (int number : res)
        cout << number << ' ';

    return 0;
}