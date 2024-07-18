/**
 * @file 1344_DP.cpp
 * @brief 00:39:26
 * @date 2024-07-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int prime[7] = { 2, 3, 5, 7, 11, 13, 17 };
ld Awin, Alose, Bwin, Blose, result;
ld table[19][19][19];   // [interval][A score][B score]

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> Awin >> Bwin;
    Awin /= 100.0; Bwin /= 100.0;
    Alose = 1.0 - Awin; Blose = 1.0 - Bwin;

    table[0][0][0] = 1;
    for (int interval = 1; interval <= 18; interval++)
        table[interval][0][0] = table[interval-1][0][0] * Alose * Blose;

    for (int interval = 1; interval <= 18; interval++) {
        for (int scoreA = 0; scoreA <= interval; scoreA++) {
            for (int scoreB = 0; scoreB <= interval; scoreB++) {
                if (!scoreA && !scoreB) continue;

                if (!scoreA) {          // A cannot get score from previous
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA][scoreB] * Alose * Blose;
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA][scoreB-1] * Alose * Bwin;
                } else if (!scoreB) {   // B cannot get score from previous
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA][scoreB] * Alose * Blose;
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA-1][scoreB] * Awin * Blose;
                } else {                // both are can get score from previous
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA][scoreB] * Alose * Blose;
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA][scoreB-1] * Alose * Bwin;
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA-1][scoreB] * Awin * Blose;
                    table[interval][scoreA][scoreB] += table[interval-1][scoreA-1][scoreB-1] * Awin * Bwin;
                }
            }
        }
    }

    for (int pa = 0; pa <= 18; pa++)
        for (int pb : prime)
            result += table[18][pa][pb];

    for (int pa : prime)
        for (int pb = 0; pb <= 18; pb++)
            result += table[18][pa][pb];

    for (int pa : prime)
        for (int pb : prime)
            result -= table[18][pa][pb];
    
    cout << result;

    return 0;
}
