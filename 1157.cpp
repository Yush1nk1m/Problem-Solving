#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;

int main()
{
    vector<int> uppercase(26);
    
    string word;
    cin >> word;
    
    const int SIZE = word.size();
    for (int i = 0; i < SIZE; i++)
    {
        uppercase[toupper(word[i]) - 65]++;
    }

    int maxIndex = 0;
    int count = 1;

    for (int i = 1; i < 26; i++)
    {
        if (uppercase[maxIndex] == uppercase[i]) count++;
        else if (uppercase[maxIndex] < uppercase[i])
        {
            maxIndex = i;
            count = 1;
        }
    }

    if (count != 1)
    {
        cout << "?";
    }
    else
    {
        cout << static_cast<char>(maxIndex + 65);
    }

    return 0;
}