/**
 * @file 11723_Bitmasking.cpp
 * @brief 00:11:26
 * @date 2024-07-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int S, M, X;
string command;

inline void Add(int x);
inline void Remove(int x);
inline bool Check(int x);
inline void Toggle(int x);
inline void All();
inline void Empty();

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for (int _ = 0; _ < M; _++) {
        cin >> command;

        if (command == "add") {
            cin >> X;
            Add(X);
        } else if (command == "remove") {
            cin >> X;
            Remove(X);
        } else if (command == "check") {
            cin >> X;
            cout << Check(X) << '\n';
        } else if (command == "toggle") {
            cin >> X;
            Toggle(X);
        } else if (command == "all") {
            All();
        } else if (command == "empty") {
            Empty();
        }
    }

    return 0;
}

inline void Add(int x) {
    S |= (1 << x);
}

inline void Remove(int x) {
    S &= ~(1 << x);
}

inline bool Check(int x) {
    return (S & (1 << x));
}

inline void Toggle(int x) {
    S ^= (1 << x);
}

inline void All() {
    S |= (1 << 21) - 1;
}

inline void Empty() {
    S &= (1 << 21);
}