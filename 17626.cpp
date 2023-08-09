#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<bool> visited;
queue<int> numbers;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> n;
    visited.resize(n + 1, false);
    numbers.push(n);

    int result = 0;
    bool is_found = false;
    while (!is_found) {
        int size = numbers.size();
        result++;

        for (int _ = 0; _ < size; _++) {
            int number = numbers.front();
            numbers.pop();

            for (int divisor = 1; divisor <= sqrtl(number); divisor++) {
                int divisor_square = divisor * divisor;
                
                if (number - divisor_square <= 0) {
                    is_found = true;
                    break;
                }

                if (!visited[number - divisor_square]) {
                    numbers.push(number - divisor_square);
                    visited[number - divisor_square] = true;
                }
            }
        }
    }

    cout << result;

    return 0;
}