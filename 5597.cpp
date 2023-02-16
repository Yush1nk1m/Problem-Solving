#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(31);

    int index;
    for (int i = 0; i < 28; i++)
    {
        cin >> index;
        vec[index] += 1;
    }
    for (int i = 1; i <= 30; i++)
    {
        if (!vec[i])
        {
            cout << i << endl;
        }
    }

    return 0;
}