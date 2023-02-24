#include <iostream>
#include <string>
using namespace std;

int main()
{
    for (int _ = 0; _ < 100; _++)
    {
        string temp;
        getline(cin, temp);
        cout << temp << endl;
    }

    return 0;
}