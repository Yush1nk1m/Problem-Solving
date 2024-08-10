/**
 * @file 17479_DataStructure.cpp
 * @brief 00:11:12
 * @date 2024-08-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

int A, B, C, N, normalPrice, specialPrice, serviceCnt;
map<string, int> normal, special;
vector<string> service;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    while (A--) {
        string menu;
        int price;
        cin >> menu >> price;
        normal[menu] = price;
    }
    while (B--) {
        string menu;
        int price;
        cin >> menu >> price;
        special[menu] = price;
    }
    while (C--) {
        string menu;
        cin >> menu;
        service.push_back(menu);
    }
    sort(service.begin(), service.end());

    cin >> N;
    while (N--) {
        string menu;
        cin >> menu;

        if (normal.find(menu) != normal.end())
            normalPrice = min(normalPrice + normal[menu], 50000);
        else if (special.find(menu) != special.end())
            specialPrice = min(specialPrice + special[menu], 50000);
        else
            serviceCnt++;
    }

    if (serviceCnt > 1 || (normalPrice + specialPrice < 50000 && serviceCnt == 1) || (normalPrice < 20000 && specialPrice > 0))
        cout << "No";
    else
        cout << "Okay";

    return 0;
}