#include <queue>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    queue<string> lines;
    int N;
    cin >> N;

    for (int _ = 0; _ < N; _++)
    {
        string temp;
        cin >> temp;
        lines.push(temp);
    }

    for (int _ = 0; _ < N; _++)
    {
        string temp = lines.front();
        lines.pop();
        cout << temp[0] << temp[temp.length() - 1] << endl;
    }

    return 0;
}