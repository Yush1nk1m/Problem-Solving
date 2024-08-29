#include <bits/stdc++.h>
using namespace std;

string input;
vector<string> words;

string Reverse(string input);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for (int i = 1; i < input.length() - 1; i++)
        for (int j = i + 1; j < input.length(); j++) {
            string generatedWord = Reverse(input.substr(0, i)) + Reverse(input.substr(i, j - i)) + Reverse(input.substr(j));
            words.push_back(generatedWord);
        }
    cout << *min_element(words.begin(), words.end());

    return 0;
}

string Reverse(string input) {
    string result = "";
    for (int i = input.length() - 1; i >= 0; i--)
        result += input[i];
    return result;
}