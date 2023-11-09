#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    set<int> numbers;
    int N; cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numbers.insert(temp);
    }

    set<int>::iterator iter;
    for (iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        cout << *iter << "\n";
    }
    return 0;
}