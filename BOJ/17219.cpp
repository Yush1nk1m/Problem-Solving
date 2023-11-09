#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> passwords;
int N, M;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;

    for (int _ = 0; _ < N; _++) {
        string url, password;
        cin >> url >> password;

        passwords[url] = password;
    }

    for (int _ = 0; _ < M; _++) {
        string url;
        cin >> url;

        cout << passwords[url] << '\n';
    }

    return 0;
}