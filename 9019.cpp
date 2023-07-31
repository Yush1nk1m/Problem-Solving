#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
using namespace std;

bitset<10000> visited;
int parents[10000];
char operations[10000];

inline int D(int n) {
    return (2 * n) % 10000;
}

inline int S(int n) {
    if (n == 0) return 9999;
    else return n - 1;
}

inline int L(int n) {
    int n1, n2, n3, n4;

    n4 = n % 10;
    n /= 10;
    n3 = n % 10;
    n /= 10;
    n2 = n % 10;
    n /= 10;
    n1 = n % 10;

    return (1000 * n2) + (100 * n3) + (10 * n4) + n1;
}

inline int R(int n) {
    int n1, n2, n3, n4;

    n4 = n % 10;
    n /= 10;
    n3 = n % 10;
    n /= 10;
    n2 = n % 10;
    n /= 10;
    n1 = n % 10;

    return (1000 * n4) + (100 * n1) + (10 * n2) + n3;
}

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        int initial_value, final_value;

        cin >> initial_value >> final_value;

        queue<int> numbers;
        visited.reset();

        numbers.push(initial_value);
        visited.set(initial_value);
        parents[initial_value] = initial_value;

        bool is_found = false;
        
        while (!is_found) {
            int number = numbers.front();
            numbers.pop();

            if (number == final_value) {
                is_found = true;
                break;
            }

            // searching unvisited neighbors
            int d = D(number), s = S(number), l = L(number), r = R(number);

            if (!visited.test(d)) {
                visited.set(d);
                parents[d] = number;
                operations[d] = 'D';
                numbers.push(d);

                if (d == final_value) {
                    is_found = true;
                    break;
                }
            }
            if (!visited.test(s)) {
                visited.set(s);
                parents[s] = number;
                operations[s] = 'S';
                numbers.push(s);

                if (s == final_value) {
                    is_found = true;
                    break;
                }
            }
            if (!visited.test(l)) {
                visited.set(l);
                parents[l] = number;
                operations[l] = 'L';
                numbers.push(l);

                if (l == final_value) {
                    is_found = true;
                    break;
                }
            }
            if (!visited.test(r)) {
                visited.set(r);
                parents[r] = number;
                operations[r] = 'R';
                numbers.push(r);

                if (r == final_value) {
                    is_found = true;
                    break;
                }
            }
        }

        int step = final_value;
        stack<char> operation_stack;
        while (step != initial_value) {
            operation_stack.push(operations[step]);
            step = parents[step];
        }
        while (!operation_stack.empty()) {
            cout << operation_stack.top();
            operation_stack.pop();
        }
        cout << '\n';
    }

    return 0;
}