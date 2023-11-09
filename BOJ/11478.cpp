#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main(int argc, char* argv[])
{
    unordered_set<string> substrs;
    
    string str;
    cin >> str;
    
    for (int l = 0; l < str.length(); ++l)
    {
        for (int r = 1; r <= str.length() - l; ++r)
        {
            substrs.insert(str.substr(l, r));
        }
    }

    cout << substrs.size();

    return 0;
}