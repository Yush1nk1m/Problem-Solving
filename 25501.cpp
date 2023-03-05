#include <iostream>
#include <string>
using namespace std;

int recursion(const string& str, int l, int r, int& repeat)
{
    ++repeat;
    if (l >= r) return 1;
    else if (str[l] != str[r]) return 0;
    else return recursion(str, l + 1, r - 1, repeat);
}

int isPalindrome(const string& str, int& repeat)
{
    return recursion(str, 0, str.length() - 1, repeat);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    string temp;
    for (int _ = 0; _ < T; ++_)
    {
        cin >> temp;
        int repeat = 0;
        cout << isPalindrome(temp, repeat) << " ";
        cout << repeat << '\n';
    }

    return 0;
}