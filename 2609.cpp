#include <iostream>
#include <numeric>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int n1, n2;

int main(int argc, char* argv[]) {
    cin >> n1 >> n2;
    int max_divisor, min_multiple;
    
    for (int i = MIN(n1, n2); i >= 1; i--)
        if (n1 % i == 0 && n2 % i == 0) {
            max_divisor = i;
            break;
        }
    
    for (min_multiple = MIN(n1, n2); !(min_multiple % n1 == 0 && min_multiple % n2 == 0); min_multiple += MIN(n1, n2));

    cout << max_divisor << endl;
    cout << min_multiple << endl;

    return 0;
}