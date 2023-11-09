#include <iostream>
#include <vector>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int L, P, V;
    int case_number = 0;
    while (1) {
        case_number++;

        cin >> L >> P >> V;
        if (!L && !P && !V) break;

        cout << "Case " << case_number << ": " << (((V / P) * L) + MIN(V % P, L)) << '\n';
    }

    return 0;
}