/**
 * @file 20546_Implementation.cpp
 * @author your name (you@domain.com)
 * @brief 00:18:14
 * @version 0.1
 * @date 2024-11-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int m1, m2;
int bnp, timing, price;
vector<int> history(15);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m1;
    m2 = m1;

    for (int i = 1; i <= 14; i++) {
        cin >> price;

        bnp += (m1 / price);
        m1 %= price;

        if (i >= 4 && history[i-3] < history[i-2] && history[i-2] < history[i-1] && history[i-1] < price) {
            m2 += (price * timing);
            timing = 0;
        } else if (i >= 4 && history[i-3] > history[i-2] && history[i-2] > history[i-1] && history[i-1] > price) {
            timing += (m2 / price);
            m2 %= price;
        }

        history[i] = price;
    }

    m1 += (bnp * price);
    m2 += (timing * price);

    if (m1 > m2)
        cout << "BNP";
    else if (m1 < m2)
        cout << "TIMING";
    else
        cout << "SAMESAME";
    
    return 0;
}