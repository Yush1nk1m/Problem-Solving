#include <iostream>
#include <vector>
using namespace std;

static int N;
static int resultLeft, resultRight;
static long long int minSum = 2000000001;
static vector<long long int> solutions;

void searchMinimumDiff(int left, int right);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solutions.resize(N);
    
    for (int i = 0; i < N; i++)
        cin >> solutions[i];

    for (int i = 0; i < N - 1 && minSum != 0; i++)
        searchMinimumDiff(i, N - 1);

    cout << solutions[resultLeft] << ' ' << solutions[resultRight];

    return 0;
}

void searchMinimumDiff(int left, int right) {
    int l = left + 1, r = right;
    while (l <= r) {
        int mid = (l + r + 1) / 2;
        long long int temp = solutions[left] + solutions[mid];

        if (llabs(temp) < minSum) {
            minSum = llabs(temp);
            resultLeft = left;
            resultRight = mid;
        }

        if (temp < 0) {
            l = mid + 1;
        } else if (temp > 0) {
            r = mid - 1;
        } else {
            return;
        }
    }
}