#include <bits/stdc++.h>
using namespace std;

int N, M;
unordered_set<string> words;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    while (N--) {
        string word;
        cin >> word;
        words.insert(word);
    }

    while (M--) {
        string line, token;
        cin >> line;
        
        istringstream iss(line);
        while (getline(iss, token, ','))
            words.erase(token);
        
        cout << words.size() << '\n';
    }

    return 0;
}