#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, n;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> T;
    for (int _ = 0; _ < T; _++) {
        unordered_map<string, int> clothes;
        cin >> n;

        for (int __ = 0; __ < n; __++) {
            string name, type;
            cin >> name >> type;

            if (clothes.find(type) == clothes.end())
                clothes[type] = 1;
            else
                clothes[type]++;
        }
        
        int result = 1;
        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            result *= (it->second + 1);
        }
        result--;
        
        cout << result << '\n';
    }

    return 0;
}