#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N; cin >> M;

    map<int, string> nameAns;
    map<string, int> numAns;

    string name;
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> name;
        nameAns.insert(pair<int, string>(i, name));
        numAns.insert(pair<string, int>(name, i));    
    }

    string question;
    int n;
    for (int i = 0; i < M; ++i)
    {
        cin >> question;
        istringstream iss(question);

        if (iss >> n)
        {
            cout << nameAns[n] << '\n';
        }
        else
        {
            cout << numAns[question] << '\n';
        }
    }

    return 0;
}