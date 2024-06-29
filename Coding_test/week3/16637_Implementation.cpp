/**
 * @file 16637_Implementation.cpp
 * @brief 01:07:23
 * @date 2024-06-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define INF 100000000

int N;
long long int maxResult;
string expression;
vector<long long int> numbers;
vector<char> operators;

inline void StringDecomposition();
inline long long int Evaluation(char op, long long int n1, long long int n2);
void FindMax(int index, long long int number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    maxResult = numeric_limits<long long int>::min();
    cin >> N;
    cin >> expression;

    StringDecomposition();
    FindMax(0, numbers[0]);
    cout << maxResult;

    return 0;
}

inline void StringDecomposition() {
    istringstream iss(expression);
    long long int number;
    char op;

    while (1) {
        if (iss >> number)
            numbers.push_back(number);
        if (iss >> op)
            operators.push_back(op);
        else break;
    }
}

inline long long int Evaluation(char op, long long int n1, long long int n2) {
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
    }
    return INF;
}

void FindMax(int index, long long int number) {
    if (index >= operators.size()) {
        maxResult = max(maxResult, number);
        return;
    }

    long long int result = Evaluation(operators[index], number, numbers[index + 1]);
    FindMax(index + 1, result);

    if (index + 1 < operators.size()) {
        result = Evaluation(operators[index + 1], numbers[index + 1], numbers[index + 2]);
        result = Evaluation(operators[index], number, result);
        FindMax(index + 2, result);
    }
}