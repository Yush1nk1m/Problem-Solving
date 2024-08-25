/**
 * @file 42842_Math.cpp
 * @brief 프로그래머스 "카펫" 00:18:12
 * @date 2024-08-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    for (int x = 3; x <= (brown - 2) / 2; x++)
        for (int y = 3; y <= x; y++)
            if (2*x + 2*y - 4 == brown && x*y - 2*x - 2*y + 4 == yellow)
                return {x, y};
}
