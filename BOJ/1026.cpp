#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B;
int N;

bool compare(int a, int b) {
    return (a < b);
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;
    A.resize(N); B.resize(N);

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end(), compare);
    sort(B.rbegin(), B.rend(), compare);

    int result = 0;
    for (int i = 0; i < N; i++) {
        result += B[i] * A[i];
    }

    cout << result;

    return 0;
}