#include <iostream>
using namespace std;

inline int fibonacci(int _number)
{
    if (_number <= 0) return 0;
    if (_number <= 1) return 1;
    return fibonacci(_number - 1) + fibonacci(_number - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n);

    return 0;
}