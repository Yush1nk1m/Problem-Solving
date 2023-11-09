#include <iostream>
#include <vector>
using namespace std;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int N, max_length = 1;
vector<int> sequence;
vector<int> length;

int main(int argc, char* argv[]) {
    cin >> N;
    
    sequence.resize(N);
    length.resize(N, 1);

    for (int i = 0; i < N; i++)
        cin >> sequence[i];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j])
                length[i] = MAX(length[i], length[j] + 1);
            
            if (max_length < length[i]) max_length = length[i];
        }
    }

    cout << max_length;

    return 0;
}