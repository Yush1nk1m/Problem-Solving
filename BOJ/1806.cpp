#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sequence;
int N, S;
int length = 1, min_length = 2147483647, accumulated_sum;
int l, r;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> S;
    sequence.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    accumulated_sum = sequence[0];
    while (r < N) {
        if (accumulated_sum < S) {
            r++;
            if (r < N) {
                length++;
                accumulated_sum += sequence[r];
            }
        }
        else {
            if (length < min_length) min_length = length;
            accumulated_sum -= sequence[l];
            l++;
            length--;
        }
    }

    if (min_length == 2147483647) cout << 0;
    else cout << min_length;

    return 0;
}