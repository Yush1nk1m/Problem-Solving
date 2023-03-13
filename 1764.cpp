#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    unordered_set<string> noHeared;
    set<string> result;

    int N, M;
    cin >> N; cin >> M;

    noHeared.reserve(N);

    string name;
    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        noHeared.insert(name);
    }
    
    for (int i = 0; i < M; ++i)
    {
        cin >> name;
        if (noHeared.find(name) != noHeared.end())
        {
            result.insert(name);
        }
    }

    cout << result.size() << '\n';
    set<string>::iterator iter;
    for (iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << '\n';
    }

    return 0;
}