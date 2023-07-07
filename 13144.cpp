#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int N, l, r;
long long result;
bitset<100001> integers;
vector<int> sequence;

int main(int argc, char* argv[]) {
    cin >> N;
    sequence.resize(N);
    
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    integers.set(sequence[r]);
    result++;

    while (1) {
        r++;
        if (r == N) break;

        while (integers.test(sequence[r])) {
            integers.reset(sequence[l]);
            l++;
        }

        integers.set(sequence[r]);
        result += (r - l + 1);
    }

    cout << result;

    return 0;
}