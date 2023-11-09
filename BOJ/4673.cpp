#include <iostream>
#include <vector>
using namespace std;

int d(int n)
{
    int ans = n;
    
    while (n > 0)
    {
        ans += (n % 10);
        n /= 10;
    }

    return ans;
}

int main()
{
    vector<int> selfNumber(10001);

    for (int number = 1; number <= 10000; number++)
    {
        if (selfNumber[number] == 0)
        {
            for (int temp = d(number); temp <= 10000; temp = d(temp))
            {
                selfNumber[temp] = 1;
            }
        }
    }

    for (int index = 1; index <= 10000; index++)
    {
        if (!selfNumber[index])
        {
            cout << index << endl;
        }
    }

    return 0;
}