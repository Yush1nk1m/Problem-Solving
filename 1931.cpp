#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;
long long fin_time = -1;
vector<pair<long long, long long>> meetings;

int main(int argc, char* argv[]) {
    cin >> N;
    meetings.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].second >> meetings[i].first;
    }

    sort(meetings.begin(), meetings.end());

    for (int i = 0; i < N; i++) {
        if (meetings[i].second >= fin_time) {
            result++;
            fin_time = meetings[i].first;
        }
    }

    cout << result;

    return 0;
}