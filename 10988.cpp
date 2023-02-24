#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string rev;
    getline(cin, rev);

    string line(rev);
    reverse(rev.begin(), rev.end());

    if (line == rev)
        cout << true;
    else
        cout << false;

    return 0;
}