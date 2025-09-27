/**
 * @file 4375.cpp
 * @brief 00:10:17
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 일의 자릿수가 1이 되면 10을 나누고 자릿수를 1 올린다.
 * 그 이후엔 한 단계 더 높은 자릿수에 입력 받은 숫자를 그대로 더하게 된다.
 * 이것은 (입력받은 숫자) * (10^k)를 더하는 것과 같다.
 */
#include <bits/stdc++.h>
using namespace std;

int N;

inline int FindMultiple(int number) {
    int cnt = 0, temp = number;
    while (temp > 0) {
        if (temp % 10 == 1) {
            temp /= 10;
            cnt++;
        }
        else {
            temp += number;
        }
    }

    return cnt;
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> N) {
        cout << FindMultiple(N) << '\n';
    }

    return 0;
}