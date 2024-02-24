#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, from, to, sum;
    cin >> N;

    long long result = 0;
    from = to = sum = 1;
    while (to <= N) {        
        if (sum < N) {
            to++;
            sum += to;
        } else if (sum > N) {
            sum -= from;
            from++;
        } else {
            result++;
            to++;
            sum += to;
        }
    }

    cout << result;

    return 0;
}