#include <iostream>
#include <vector>
using namespace std;

int recCount = 0, dnmCount = 0;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        ++recCount;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    vector<int> sequence(n + 1, 1);
    for (int i = 3; i <= n; ++i)
    {
        sequence[i] = sequence[i - 1] + sequence[i - 2];
        ++dnmCount;
    }
    return sequence[n];
}

int main(int argc, char* argv[])
{
    int N;
    cin >> N;

    fib(N);
    fibonacci(N);

    cout << recCount << ' ' << dnmCount;

    return 0;
}