#include <iostream>
using namespace std;

int array[5];

int main(int argc, char* argv[])
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        cin >> array[i];
        sum += array[i] * array[i];
    }

    cout << sum % 10;

    return 0;
}