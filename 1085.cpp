#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int x, y, w, h;

int main(int argc, char* argv[]) {
    cin >> x >> y >> w >> h;

    int result = MIN(x, MIN(w - x, MIN(y, h - y)));

    cout << result;

    return 0;
}