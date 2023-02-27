#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int num5 = N / 5 + 2;   // row
    int num3 = N / 3 + 2;   // column

    vector<vector<int>> result(num5, vector<int>(num3, 0));

    for (int _5kilos = 0; _5kilos < num5; _5kilos++)
    {
        for (int _3kilos = 0; _3kilos < num3; _3kilos++)
        {
            int temp = _5kilos * 5 + _3kilos * 3;
            if (temp == N) result[_5kilos][_3kilos] = _5kilos + _3kilos;
            else result[_5kilos][_3kilos] = -1;
        }
    }

    int current = -1;
    for (int _3kilos = 0; _3kilos < num3 && current == -1; _3kilos++)
    {
        for (int _5kilos = 0; _5kilos < num5 && current == -1; _5kilos++)
        {
            if (result[_5kilos][_3kilos] != -1) current = result[_5kilos][_3kilos];
        }
    }
    
    cout << current;

    return 0;
}