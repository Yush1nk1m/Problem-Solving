#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline bool compare(string& left, string& right)
{
    if (left.length() == right.length())
    {
        return left < right;
    }
    return left.length() < right.length();
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    vector<string> words;
    string word;

    int N;
    cin >> N;

    for (int _ = 0; _ < N; _++)
    {
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    vector<string>::iterator iter;
    for (iter = words.begin(); iter != words.end(); iter++)
    {
        cout << *iter << '\n';
    }
    
    return 0;
}