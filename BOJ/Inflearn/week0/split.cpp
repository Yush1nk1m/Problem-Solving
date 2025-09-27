#include <bits/stdc++.h>
using namespace std;

vector<string> split(string input, char delim) {
    istringstream iss(input);
    vector<string> res;
    string token;

    while (getline(iss, token, delim))
        res.push_back(token);

    return res;
}

int main(int argc, char* argv[]) {
    string input = "first second third fourth fiveth";

    vector<string> res = split(input, ' ');

    for (string token : res)
        cout << token << endl;

    return 0;
}