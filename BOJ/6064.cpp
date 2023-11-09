#include <iostream>
using namespace std;

int T, M, N, x, y;
pair<int, int> calendar;

inline int getGCD(int x, int y) {
    int a = x;
    int b = y;
    int remainder = a % b;

    while (remainder != 0) {
        a = b;
        b = remainder;
        remainder = a % b;
    }

    return b;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> M >> N >> x >> y;

        int k = x;
        
        int gcd = (M > N) ? getGCD(M, N) : getGCD(N, M);
        int lcm = M * N / gcd;

        calendar = {x, x % N};
        if (calendar.second == 0) calendar.second = N;

        while (k <= lcm) {
            if (calendar.first == x && calendar.second == y) break;
            
            calendar.second = (calendar.second + M) % N;
            if (calendar.second == 0) calendar.second = N;
            
            k += M;
        }

        if (k <= lcm) cout << k << '\n';
        else cout << -1 << '\n';
    }
}