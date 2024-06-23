/**
 * @file 1213_Hash_String.cpp
 * @brief 00:10:37
 * @date 2024-06-23
 * 
 * @copyright Copyright (c) 2024
 * 홀수 개인 원소가 단 하나만 있어야 하고, 해당 원소를 가운데 배치(맨 처음 삽입)
 * 나머지 원소를 덱의 앞뒤에 하나씩 넣어주면 사전순으로 정렬된 팰린드롬 생성
 */

#include <bits/stdc++.h>
using namespace std;

string name;
map<char, int> alphamap;
deque<char> dq;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (char c = 'A'; c <= 'Z'; c++)
        alphamap[c] = 0;

    cin >> name;
    for (char c : name) {
        alphamap[c]++;
    }

    int oddCount = 0;
    char oddAlpha;
    for (char c = 'A'; c <= 'Z'; c++)
        if (alphamap[c] % 2 != 0) {
            oddCount++;
            oddAlpha = c;
            alphamap[c]--;
        }
    
    if ((name.length() % 2 == 0 && oddCount != 0) ||
        (name.length() % 2 != 0 && oddCount != 1)) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    if (oddCount == 1)
        dq.push_back(oddAlpha);

    for (char c = 'Z'; c >= 'A'; c--) {
        while (alphamap[c] > 0) {
            alphamap[c] -= 2;
            dq.push_front(c);
            dq.push_back(c);
        }
    }
    
    for (char c : dq)
        cout << c;

    return 0;
}