#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int min, max;
    cin >> min >> max;
    
    int num_elements = max - min + 1;
    vector<bool> sieve(sqrtl(max) + 1, true);
    vector<bool> result_array(num_elements, true);
    vector<long long int> squares;

    for (long long int n = 2; n <= sqrtl(max); n++) {
        if (sieve[n]) {
            for (long long int multiple = n * 2; multiple <= sqrtl(max); multiple += n)
                sieve[multiple] = false;
            squares.push_back(powl(n, 2));
        }
    }
    
    for (long long int square : squares) {
        long long int adder = square;
        square = (min / square) * square;

        while (square < min)
            square += adder;

        while (square <= max) {
            result_array[square - min] = false;
            square += adder;
        }
    }

    int result = 0;
    for (int i = 0; i < num_elements; i++)
        result += static_cast<int>(result_array[i]);

    cout << result;

    return 0;
}