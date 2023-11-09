#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int input[8001] = { 0 };

    int N, temp, accumulated = 0, maxFrequency = -1, maxFrequencyValue,
    idxChangedCount = 0, medium = 0, count = 0, low = 0, high = 8000;
    double average = 0.0;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        average += temp;
        ++input[temp + 4000];
    }
    average /= static_cast<double>(N);

    while (!input[low]) ++low;
    low -= 4000;
    while (!input[high]) --high;
    high -= 4000;

    for (int i = 0; i <= 8000; ++i)
    {
        count += input[i];
        if (count > N / 2)
        {
            medium = i - 4000;
            break;
        }
    }

    for (int i = 0; i <= 8000; ++i)
    {
        if (input[i] > maxFrequency) maxFrequency = input[i];
    }

    for (int i = 0; i <= 8000; ++i)
    {
        if (input[i] == maxFrequency)
        {
            maxFrequencyValue = i - 4000;
            ++idxChangedCount;
        }
        if (idxChangedCount == 2)
        {
            break;
        }
    }

    average = round(average);
    if (average == -0.0)
    {
        cout << fabs(average) << '\n';
    }
    else
    {
        cout << average << '\n';
    }
    cout << medium << '\n';
    cout << maxFrequencyValue << '\n';
    cout << high - low;

    return 0;
}