#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int nA, nB;
    cin >> nA; cin >> nB;

    unordered_set<int> A;
    unordered_set<int> B;

    int element;
    for (int i = 0; i < nA; ++i)
    {
        cin >> element;
        A.insert(element);
    }
    
    for (int i = 0; i < nB; ++i)
    {
        cin >> element;
        if (A.find(element) != A.end())
        {
            A.erase(element);
        }
        else
        {
            B.insert(element);
        }
    }

    cout << A.size() + B.size();

    return 0;
}