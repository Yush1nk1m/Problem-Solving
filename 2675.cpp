#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    vector<string> strings(T);

    for (int i = 0; i < T; i++)
    {
        int repeat;
        string origin;
        cin >> repeat;
        cin >> origin;

        string newString("");
        const int SIZE = origin.size();
        for (int index = 0; index < SIZE; index++)
        {
            newString += string(repeat, origin[index]);
        }
        
        strings[i] = newString;
    }

    vector<string>::iterator iter;
    for (iter = strings.begin(); iter != strings.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}