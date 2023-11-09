#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> pinary;

int main(int argc, char* argv[]) {
    cin >> N;

    pinary.resize(N + 1, 0);
    
    pinary[1] = 1;
    for (int i = 2; i <= N; i++)
        pinary[i] = pinary[i - 1] + pinary[i - 2];

    cout << pinary[N];

    return 0;
}