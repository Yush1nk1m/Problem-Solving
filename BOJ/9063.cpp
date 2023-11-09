#include <iostream>
using namespace std;

int N, x, y;
int min_x = 10000, max_x = -10000, min_y = 10000, max_y = -10000;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N;

    for (int _ = 0; _ < N; _++) {
        cin >> x >> y;

        if (x < min_x) min_x = x;
        if (x > max_x) max_x = x;
        if (y < min_y) min_y = y;
        if (y > max_y) max_y = y;
    }

    cout << ((max_x - min_x) * (max_y - min_y));

    return 0;
}