#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream file("input.txt");

    file << 100000 << endl;
    for (int i = 2; i <= 100000; i++) {
        file << 1 << ' ' << i << ' ';
    }
    file << 1 << ' ' << -1 << endl;

    for (int i = 2; i <= 100000; i++) {
        file << i << " 1 1 -1\n";
    }

    return 0;
}