#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<long long> numbers(N);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    
    int result = 0;
    for (int target = 0; target < N; target++) {
        int from = 0, to = N - 1;
        while (from < to) {
            long long sum = numbers[from] + numbers[to];
            
            if (sum < numbers[target]) {
                from++;
            } else if (sum > numbers[target]) {
                to--;
            } else {
                if (from == target) {
                    from++;
                } else if (to == target) {
                    to--;
                } else {
                    result++;
                    break;
                }
            }
        }
    }

    cout << result;

    return 0;
}