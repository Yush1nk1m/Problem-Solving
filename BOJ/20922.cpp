#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;
short dup_numbers[200001];

int N, K;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    sequence.resize(N);
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    int l, r, len, max_len;
    
    l = 0;
    r = 1;
    max_len = len = 1;
    dup_numbers[sequence[0]]++;

    while (r < N) {
        if (dup_numbers[sequence[r]] >= K) {
            dup_numbers[sequence[l]]--;
            l++;
            len--;
        }
        else {
            dup_numbers[sequence[r]]++;
            r++;
            len++;

            if (max_len < len) max_len = len;
        }
    }

    cout << max_len;

    return 0;
}