#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, time, minimum_time;
vector<int> P;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;
    P.resize(N);

    for (int i = 0; i < N; i++) cin >> P[i];
    sort(P.begin(), P.end());

    for (int i = 0; i < N; i++) {
        time += P[i];
        minimum_time += time;
    }

    cout << minimum_time;

    return 0;
}