#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> primeNumbers(1001, true);
    primeNumbers[1] = false;

    int next = 2;
    for (int current = next; current <= 1000; current = next)
    {
        int multiple = current * 2;
        while (multiple <= 1000)
        {
            primeNumbers[multiple] = false;
            multiple += current;
        }
        
        next = current + 1;
        while (!primeNumbers[next] && next <= 1000) next++;
    }

    int count = 0, N;
    cin >> N;
    for (int _ = 0; _ < N; _++)
    {
        int temp;
        cin >> temp;
        if (primeNumbers[temp]) count++;
    }
    
    cout << count;

    return 0;
}