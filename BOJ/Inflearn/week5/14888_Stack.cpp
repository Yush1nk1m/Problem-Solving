/**
 * @file 14888_Stack.cpp
 * @brief 00:33:50
 * @date 2024-07-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1000000001

#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3

int N;
ll minRes = INF, maxRes = -INF;
vector<int> numbers;
vector<int> operations;
vector<int> sequence;

inline ll Calculation(vector<int>& opSeq);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    numbers.resize(N);
    operations.resize(4, 0);
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    for (int i = 0; i < 4; i++)
        cin >> operations[i];

    for (int op = 0; op < 4; op++)
        for (int i = 0; i < operations[op]; i++)
            sequence.push_back(op);
    
    do {
        ll res = Calculation(sequence);
        if (res != INF) {
            minRes = min(minRes, res);
            maxRes = max(maxRes, res);
        }
    } while (next_permutation(sequence.begin(), sequence.end()));

    cout << maxRes << '\n' << minRes << endl;
}

inline ll Calculation(vector<int>& opSeq) {
    stack<ll> stk;
    for (auto it = numbers.rbegin(); it != numbers.rend(); it++)
        stk.push(*it);

    for (int op : opSeq) {
        ll n1 = stk.top(); stk.pop();
        ll n2 = stk.top(); stk.pop();

        if (op == ADD)
            stk.push(n1 + n2);
        else if (op == SUB)
            stk.push(n1 - n2);
        else if (op == MUL)
            stk.push(n1 * n2);
        else if (op == DIV)
            stk.push(n1 / n2);
    }

    return stk.top();
}