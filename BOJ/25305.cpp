#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, k;
    cin >> N; cin >> k;
    vector<int> numbers;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    sort(numbers.rbegin(), numbers.rend());

    cout << numbers[k - 1];

    return 0;
}