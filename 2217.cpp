#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, max_weight;
vector<int> ropes;

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    ropes.resize(N);
    for (int i = 0; i < N; i++)
        cin >> ropes[i];

    sort(ropes.begin(), ropes.end());
    
    int rope = 0;
    while (rope < N) {
        int w = ropes[rope];
        if (max_weight < w * (N - rope)) max_weight = w * (N - rope);

        while (rope < N && ropes[rope] == w) rope++;
    }

    cout << max_weight;

    return 0;
}
