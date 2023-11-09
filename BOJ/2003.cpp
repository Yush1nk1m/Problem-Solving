#include <iostream>
#include <vector>
using namespace std;

int N, M, l, r, Sum, result;
vector<int> sequence;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    sequence.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    Sum += sequence[0];

    while (1) {
        if (Sum < M) {
            r++;
            if (r >= N) break;
            Sum += sequence[r];
        }
        else if (Sum == M) {
            result++;
            Sum -= sequence[l];
            l++;
        }
        else {
            Sum -= sequence[l];
            l++;
        }
    }

    cout << result;

    return 0;
}