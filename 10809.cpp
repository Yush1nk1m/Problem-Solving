#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> lowercase(26, -1);  // c - 26
    
    string word;
    cin >> word;

    const int SIZE = word.size();
    for (int i = 0; i < SIZE; i++)
    {
        if (lowercase[word[i] - 97] == -1)
        {
            lowercase[word[i] - 97] = i;
        }
    }

    vector<int>::iterator iter;
    for (iter = lowercase.begin(); iter != lowercase.end(); iter++)
    {
        cout << *iter << " ";
    }

    return 0;
}