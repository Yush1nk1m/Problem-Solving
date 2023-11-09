#include <iostream>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

queue<int> numbers;
int number;
char op;
string line;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    getline(cin, line);

    istringstream iss(line);

    iss >> number;
    while (iss >> op) {
        if (op == '+') {
            int temp;
            iss >> temp;

            number += temp;
        }
        else if (op == '-') {
            numbers.push(number);

            iss >> number;
        }
    }
    numbers.push(number);

    int result = numbers.front();
    numbers.pop();

    while (!numbers.empty()) {
        result -= numbers.front();
        numbers.pop();
    }

    cout << result;

    return 0;
}