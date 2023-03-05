#include <iostream>
using namespace std;

inline int factorial(int _number)
{
    if (_number <= 1) return 1;
    return (_number * factorial(_number - 1));
}

int main()
{
    int N;
    cin >> N;

    cout << factorial(N);

    return 0;
}