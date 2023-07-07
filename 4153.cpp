#include <iostream>
#include <algorithm>
using namespace std;

int lines[3];

int main(int argc, char* argv[]) {
    while (1) {
        cin >> lines[0] >> lines[1] >> lines[2];
        if (lines[0] == 0 && lines[1] == 0 && lines[2] == 0) break;

        sort(lines, lines + 3);

        if (lines[0] * lines[0] + lines[1] * lines[1] == lines[2] * lines[2]) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}