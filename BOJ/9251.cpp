#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> LCStable(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (int p1 = 1; p1 <= str1.size(); p1++) {
        for (int p2 = 1; p2 <= str2.size(); p2++) {
            if (str1[p1-1] == str2[p2-1]) {
                LCStable[p1][p2] = LCStable[p1-1][p2-1] + 1;
            }
            else {
                LCStable[p1][p2] = max(LCStable[p1-1][p2], LCStable[p1][p2-1]);
            }
        }
    }

    cout << LCStable[str1.size()][str2.size()];

    return 0;
}