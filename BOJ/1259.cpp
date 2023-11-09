#include <iostream>
#include <string>
using namespace std;

string input;

int main(int argc, char* argv[]) {
    while (1) {
        cin >> input;
        if (input == "0") break;

        int i;
        for (i = 0; i < input.length() / 2; i++) {
            if (input[i] != input[input.length() - 1 - i]) break;
        }

        if (i == input.length() / 2) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}