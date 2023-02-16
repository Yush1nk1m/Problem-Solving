#include <iostream>
#include <string>
using namespace std;

int chartime[] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};

int main()
{
    int ans = 0;

    string word;
    getline(cin, word);

    for (int i = 0; i < word.size(); i++)
    {
        ans += chartime[word[i] - 65];
    }

    cout << ans;

    return 0;
}