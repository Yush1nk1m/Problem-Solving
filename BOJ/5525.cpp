#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
string S;
string pattern;
vector<int> max_affix;

/*
inline void getMaxAffix(string pattern, vector<int>& affix) {
    int pattern_length = pattern.length();
    
    int len = 0, i = 1;
    affix[0] = 0;

    while (i < pattern_length) {
        if (pattern[i] == pattern[len]) {
            len++;
            affix[i] = len;
            i++;
        }
        else {
            if (len == 0) {
                affix[i] = 0;
                i++;
            }
            else {
                len = affix[len - 1];
            }
        }
    }
}
*/

inline void getPseudoAffix(int pattern_length, vector<int>& affix) {
    int i = 2;
    int len = 1;

    while (i < pattern_length)
        affix[i++] = len++;
}

inline int KMPsearching(string pattern, string str, const vector<int>& affix) {
    const int string_length = str.length();
    const int pattern_length = pattern.length();

    int string_index = 0;
    int pattern_index = 0;

    int result = 0;

    while (string_index < string_length) {
        if (str[string_index] == pattern[pattern_index]) {
            string_index++;
            pattern_index++;
        }

        if (pattern_index == pattern_length) {
            result++;
            pattern_index = affix[pattern_index - 1];
        }
        else if (string_index < string_length && pattern[pattern_index] != str[string_index]) {
            if (pattern_index == 0) string_index++;
            else pattern_index = affix[pattern_index - 1];
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M >> S;
    
    pattern.resize(2 * N + 1);
    max_affix.resize(2 * N + 1, 0);
    for (int i = 0; i < 2 * N + 1; i++) {
        pattern[i] = (i % 2) ? 'O' : 'I';
    }

    getPseudoAffix(pattern.size(), max_affix);
    int result = KMPsearching(pattern, S, max_affix);

    cout << result;

    return 0;
}