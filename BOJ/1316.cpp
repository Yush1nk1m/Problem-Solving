#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int count = 0;
    for (int _ = 0; _ < N; _++)
    {
        set<char> characters;

        string temp;
        cin >> temp;

        int i = 0;
        bool isGroupWord = true;
        while (i < temp.length())
        {
            if (characters.find(temp[i]) == characters.end())
            {
                characters.insert(temp[i]);
                i++;

                while (temp[i] == temp[i - 1] && i < temp.length()) i++; 
            }
            else
            {
                isGroupWord = false;
                break;
            }
        }
        if (isGroupWord) count++;
    }

    cout << count;

    return 0;
}