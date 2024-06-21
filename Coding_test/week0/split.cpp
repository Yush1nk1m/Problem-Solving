#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, char delim) {
    istringstream iss(input);
    string token;
    vector<string> tokens;

    while (getline(iss, token, delim))
        tokens.push_back(token);
    
    return tokens;
}

int main(int argc, char* argv[]) {
    string example = "first second third fourth fiveth";
    vector<string> tokens = split(example, ' ');
    
    for (string token : tokens)
        cout << token << '\n';
    
    return 0;
}