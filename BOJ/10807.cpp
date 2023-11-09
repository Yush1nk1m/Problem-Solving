#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec(201);
    
    int N, index;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> index;
        vec[index + 100]++;
    }

    int search;
    cin >> search;
    cout << vec[search + 100];

    return 0;
}