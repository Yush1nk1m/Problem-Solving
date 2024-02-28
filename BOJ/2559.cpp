#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int from = 0, to = K - 1;

    vector<int> temperatures(N);
    for (int i = 0; i < N; i++)
        cin >> temperatures[i];
    
    int sum = 0, result;
    for (int i = 0; i < K; i++)
        sum += temperatures[i];
    result = sum;

    while (to < N - 1) {
        sum -= temperatures[from++];
        sum += temperatures[++to];
        if (result < sum) result = sum;
    }

    cout << result;

    return 0;
}