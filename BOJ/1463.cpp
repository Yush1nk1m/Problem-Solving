#include <iostream>
#include <vector>
#define MIN(a, b) (a < b ? a : b)
using namespace std;

int main(int argc, char* argv[])
{
    int N;
    cin >> N;

    vector<int> numbers(N + 1, 0);
    
    for (int i = 2; i <= N; ++i)
    {
        numbers[i] = 1 + numbers[i-1];

        if (i % 2 == 0) numbers[i] = MIN(numbers[i], 1 + numbers[i/2]);
        if (i % 3 == 0) numbers[i] = MIN(numbers[i], 1 + numbers[i/3]);
    }

    cout << numbers[N];

    return 0;
}