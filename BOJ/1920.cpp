#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long integers[100000];

int N, M;
long long number;

bool binarySearch(long long number) {

    int low, mid, high;

    low = 0;
    high = N - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (integers[mid] == number) return true;
        else if (integers[mid] < number) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> integers[i];
    sort(integers, integers + N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> number;
        cout << binarySearch(number) << '\n';
    }
    
    return 0;
}