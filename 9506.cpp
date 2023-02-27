#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    while (true)
    {
        int input;
        cin >> input;
        if (input == -1) break;

        vector<int> divisors;

        for (int i = 1; i < input; i++)
        {
            if (input % i == 0) divisors.push_back(i);
        }

        if (accumulate(divisors.begin(), divisors.end(), 0) == input)
        {
            cout << input << " = ";
            for (int i = 0; i < divisors.size() - 1; i++)
            {
                cout << divisors[i] << " + ";
            }
            cout << divisors[divisors.size() - 1] << endl;
        }
        else
        {
            cout << input << " is NOT perfect." << endl;
        }
    }

    return 0;
}