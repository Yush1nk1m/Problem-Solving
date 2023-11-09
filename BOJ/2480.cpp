#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(7, 0);
    int index, maxFreqIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        cin >> index;
        vec[index]++;
        if (vec[index] > 1) maxFreqIndex = index;
    }
    
    if (maxFreqIndex == -1)
    {
        int i = 6;
        while (vec[i] == 0) i--;
        cout << i * 100;
    }
    else if (vec[maxFreqIndex] == 2)
    {
        cout << 1000 + (maxFreqIndex * 100);
    }
    else
    {
        cout << 10000 + (maxFreqIndex * 1000);
    }
    return 0;
}