#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    vector<string> lines;
    int maxCharNum = 0;
    for (int i = 0; i < 5; i++)
    {
        string temp;
        getline(cin, temp);
        lines.push_back(temp);
        if (temp.length() > maxCharNum)
        {
            maxCharNum = temp.length();
        }
    }

    char** table = new char*[5];
    for (int i = 0; i < 5; i++)
    {
        table[i] = new char[maxCharNum];
        strcpy(table[i], lines[i].c_str());
        for (int j = lines[i].length(); j < maxCharNum; j++)
        {
            table[i][j] = 0;
        }
    }

    for (int c = 0; c < maxCharNum; c++)
        for (int r = 0; r < 5; r++)
            if (table[r][c] != 0) cout << table[r][c];
    

    for (int i = 0; i < 5; i++) delete[] table[i];
    delete[] table;

    return 0;
}