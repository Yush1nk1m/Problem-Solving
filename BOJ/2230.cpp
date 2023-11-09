#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sequence;
int N, M, difference, min_difference = 2147483647;
int l = 0, r = 0;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    sequence.resize(N);

    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    
    sort(sequence.begin(), sequence.end());

    while (l < N && r < N) {
        difference = sequence[r] - sequence[l];
        
        if (difference < M) r++;
        else {
            if (min_difference > difference)
                min_difference = difference;
            l++;
        }
    }

    cout << min_difference;

    return 0;
}