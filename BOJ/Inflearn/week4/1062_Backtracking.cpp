/**
 * @file 1062_Backtracking.cpp
 * @brief 00:19:24
 * @date 2024-07-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int N, K, maxWords;
bool teached[26];
vector<string> words;

inline int Readable();
void Teach(char from, int depth);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (char c : { 'a', 'c', 'i', 'n', 't' })
        teached[c - 'a'] = true;

    cin >> N >> K;
    words.resize(N);
    for (int i = 0; i < N; i++)
        cin >> words[i];

    if (K < 5) {
        cout << 0;
        return 0;
    }

    Teach('b', 0);
    cout << maxWords;

    return 0;
}

inline int Readable() {
    int cnt = 0;
    for (string word : words) {
        bool readable = true;
        for (char c : word)
            if (!teached[c - 'a']) {
                readable = false;
                break;
            }
        if (readable) cnt++;
    }
    return cnt;
}

void Teach(char from, int depth) {
    if (depth == K - 5) {        
        maxWords = max(maxWords, Readable());
        return;
    }

    for (char c = from; c <= 'z'; c++)
        if (!teached[c - 'a']) {
            teached[c - 'a'] = true;
            Teach(c, depth + 1);
            teached[c - 'a'] = false;
        }
}