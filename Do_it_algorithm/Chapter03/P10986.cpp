#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; long long M;
    cin >> N >> M;
    
    vector<long long> sum(N + 1, 0);
    vector<int> remainder_counter(M, 0);
    
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    for (int i = 1; i <= N; i++) {
        sum[i] %= M;
        remainder_counter[sum[i]]++;
    }

    long long result = remainder_counter[0];
    for (int i = 0; i < M; i++) {
        long long count = remainder_counter[i];
        if (count >= 2)
            result += (count * (count - 1) / 2);
    }

    cout << result;

    return 0;
}