#include <iostream>
using namespace std;

int main()
{
    int A, B, V;
    cin >> A; cin >> B; cin >> V;

    V -= A;
    if (V % (A - B) == 0) cout << V / (A - B) + 1;
    else cout << V / (A - B) + 2;

    return 0;
}