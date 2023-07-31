#include <iostream>
#include <vector>
using namespace std;

inline long long SearchProperLength(const vector<long long>& trees, long long min_height, long long max_height, long long target) {
    long long low = 0, high = max_height;
    long long proper_sum = 2147483647, result = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long temp_sum = 0;

        for (long long i = 0; i < trees.size(); i++)
            temp_sum += ((trees[i] > mid) ? trees[i] - mid : 0);
        
        if (temp_sum >= target && temp_sum < proper_sum) {
            proper_sum = temp_sum;
            result = mid;
        }

        if (temp_sum < target) {
            high = mid - 1;
        }
        else if (temp_sum > target) {
            low = mid + 1;
        }
        else {
            break;
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N, 0);

    long long min_height = 2147483647, max_height = 0;
    for (long long i = 0; i < N; i++) {
        cin >> trees[i];

        if (trees[i] < min_height) min_height = trees[i];
        if (trees[i] > max_height) max_height = trees[i];
    }

    cout << SearchProperLength(trees, min_height, max_height, M);

    return 0;
}