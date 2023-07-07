#include <iostream>
#include <string>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int N;
int num2, num5;

int main(int argc, char* argv[]) {
    cin >> N;

    if (N == 0) cout << 0;
    else {
        for (int i = N; i > 1; i--) {
            int temp = i;
            while (temp % 5 == 0) {
                num5++;
                temp /= 5;
            }
            while (temp % 2 == 0) {
                num2++;
                temp /= 2;
            }
        }

        cout << MIN(num2, num5);
    }
    
    return 0;
}