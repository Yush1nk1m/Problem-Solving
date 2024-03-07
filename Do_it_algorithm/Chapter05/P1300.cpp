#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    int answer;
    int start = 1, end = k;
    while (start <= end) {
        int mid = (start + end) / 2;
        int count = 0;

        for (int i = 1; i <= min(N, k); i++)
            count += min(N, mid / i);

        if (count < k) {
            start = mid + 1;
        } else {
            end = mid - 1;
            answer = mid;
        }
    }

    cout << answer;

    return 0;
}