#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bitset<21> S;
int M, x;
string cmd;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    cin >> M;
    for (int _ = 0; _ < M; _++) {
        cin >> cmd;

        if (cmd == "add") {
            cin >> x;
            S.set(x);
        }
        else if (cmd == "remove") {
            cin >> x;
            S.reset(x);
        }
        else if (cmd == "check") {
            cin >> x;
            if (S.test(x)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (cmd == "toggle") {
            cin >> x;
            S[x] = !(S.test(x));
        }
        else if (cmd == "all") {
            S.set();
        }
        else if (cmd == "empty") {
            S.reset();
        }
    }
}