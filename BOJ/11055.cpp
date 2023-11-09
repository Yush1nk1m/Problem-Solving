#include <iostream>
#include <vector>
using namespace std;

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int N, maxsum;
vector<int> sequence;
vector<int> partsum;

int main(int argc, char* argv[]) {
    cin >> N;

    sequence.resize(N + 1, 0);
    partsum.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
        partsum[i] = sequence[i];
    }
    
    maxsum = partsum[1];
    
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                partsum[i] = MAX(partsum[i], partsum[j] + sequence[i]);
                if (maxsum < partsum[i]) maxsum = partsum[i];
            }
        }
    }

    cout << maxsum;

    return 0;
}