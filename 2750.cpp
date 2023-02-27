#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    set<int> numbers;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numbers.insert(temp);
    }

    for (set<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}