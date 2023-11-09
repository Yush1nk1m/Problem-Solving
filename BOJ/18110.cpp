#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, trunc_num;
double result;
vector<int> scores;

int main(int argc, char* argv[]) {
    cin >> n;
    
    if (n == 0) {
        cout << 0;
        return 0;
    }

    scores.resize(n, 0);

    trunc_num = round(n * 0.15);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    sort(scores.begin(), scores.end());

    for (int i = trunc_num; i < n - trunc_num; i++) {
        result += scores[i];
    }
    result /= static_cast<double>(n - 2 * trunc_num);

    cout << static_cast<int>(round(result));

    return 0;
}