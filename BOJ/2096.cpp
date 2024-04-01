#include <iostream>
using namespace std;

static int N;
static int priorMin[3], priorMax[3], curr[3], temp[3];

static void PrintMin() {
    cout << "MIN: ";
    for (auto mini : priorMin) cout << mini << ' ';
    cout << '\n';
}

static void PrintMax() {
    cout << "MAX: ";
    for (auto maxi : priorMax) cout << maxi << ' ';
    cout << '\n';
}

static void PrintCurr() {
    cout << "CURR: ";
    for (auto c : curr) cout << c << ' ';
    cout << '\n';
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cin >> curr[0] >> curr[1] >> curr[2];
    priorMin[0] = priorMax[0] = curr[0];
    priorMin[1] = priorMax[1] = curr[1];
    priorMin[2] = priorMax[2] = curr[2];

    
    for (int _ = 1; _ < N; _++) {
        cin >> curr[0] >> curr[1] >> curr[2];

        temp[0] = min(priorMin[0], priorMin[1]);
        temp[1] = min(min(priorMin[0], priorMin[1]), priorMin[2]);
        temp[2] = min(priorMin[1], priorMin[2]);

        priorMin[0] = temp[0] + curr[0];
        priorMin[1] = temp[1] + curr[1];
        priorMin[2] = temp[2] + curr[2];

        temp[0] = max(priorMax[0], priorMax[1]);
        temp[1] = max(max(priorMax[0], priorMax[1]), priorMax[2]);
        temp[2] = max(priorMax[1], priorMax[2]);

        priorMax[0] = temp[0] + curr[0];
        priorMax[1] = temp[1] + curr[1];
        priorMax[2] = temp[2] + curr[2];

        // PrintCurr();
        // PrintMax();
        // PrintMin();
    }

    cout << max(max(priorMax[0], priorMax[1]), priorMax[2]) << ' ' << min(min(priorMin[0], priorMin[1]), priorMin[2]);

    return 0;
}