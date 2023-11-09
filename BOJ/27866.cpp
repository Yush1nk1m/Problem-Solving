#include <iostream>
#include <string>
using namespace std;

string word;
int i;

int main(int argc, char* argv[]) {
    getline(cin, word);
    cin >> i;
    cout << word[i - 1];

    return 0;
}