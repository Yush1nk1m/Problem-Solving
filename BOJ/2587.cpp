#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    vector<int> numbers;
    for (int i = 0; i < 5; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.begin(), numbers.end());
    cout << accumulate(numbers.begin(), numbers.end(), 0) / 5 << endl;
    cout << numbers[2] << endl;

    return 0;
}