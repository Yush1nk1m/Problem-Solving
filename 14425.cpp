#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N; cin >> M;

    set<string> strings;
    string temp;

    for (int _ = 0; _ < N; ++_)
    {
        cin >> temp;
        strings.insert(temp);        
    }

    int count = 0;
    for (int _ = 0; _ < M; ++_)
    {
        cin >> temp;
        if (strings.find(temp) != strings.end())
        {
            ++count;
        }
    }

    cout << count;

    return 0;
}