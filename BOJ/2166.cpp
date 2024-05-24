#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<long long int, long long int>> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i].first >> points[i].second;
    
    long long int result = 0;
    for (int i = 0; i < N; i++)
        result += (points[i].first * points[(i+1) % (N)].second) - (points[i].second * points[(i+1) % (N)].first);
    result = llabs(result);

    cout << fixed << setprecision(1) << result / 2.0;

    return 0;
}