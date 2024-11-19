/**
 * @file 20923_Implementation.cpp
 * @brief 00:27:49
 * @date 2024-11-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
bool doTurn = true;
deque<int> doDeck, suDeck, doGround, suGround;

inline bool proceed(bool doTurn);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    doDeck.resize(N); suDeck.resize(N);
    for (int i = 0; i < N; i++)
        cin >> doDeck[i] >> suDeck[i];

    while (M--) {
        if (proceed(doTurn))
            break;
        doTurn = !doTurn;
    }

    if (doDeck.size() > suDeck.size())
        cout << "do";
    else if (doDeck.size() < suDeck.size())
        cout << "su";
    else
        cout << "dosu";

    return 0;
}

inline bool proceed(bool doTurn) {
    if (doTurn) {
        doGround.push_back(doDeck.back());
        doDeck.pop_back();

        if (doDeck.empty())
            return true;
    } else {
        suGround.push_back(suDeck.back());
        suDeck.pop_back();

        if (suDeck.empty())
            return true;
    }

    if (!doGround.empty() && doGround.back() == 5 || !suGround.empty() && suGround.back() == 5) {
        while (!suGround.empty()) {
            doDeck.push_front(suGround.front());
            suGround.pop_front();
        }

        while (!doGround.empty()) {
            doDeck.push_front(doGround.front());
            doGround.pop_front();
        }
    } else if (!doGround.empty() && !suGround.empty() && doGround.back() + suGround.back() == 5) {
        while (!doGround.empty()) {
            suDeck.push_front(doGround.front());
            doGround.pop_front();
        }

        while (!suGround.empty()) {
            suDeck.push_front(suGround.front());
            suGround.pop_front();
        }
    }

    return false;
}