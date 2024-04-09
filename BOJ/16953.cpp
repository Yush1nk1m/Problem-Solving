#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int depth = 1;
    bool isReached = false;

    unsigned long long int begin, target;
    cin >> begin >> target;
    
    queue<unsigned long long int> numbers;
    numbers.push(begin);
    while (!numbers.empty() && !isReached) {
        ++depth;
        int size = numbers.size();
        for (int _ = 0; _ < size; _++) {
            unsigned long long int curr = numbers.front();
            numbers.pop();

            if (curr * 2 == target || curr * 10 + 1 == target) {
                isReached = true;
                break;
            }
            
            if (curr * 2 < target)
                numbers.push(curr * 2);
            if (curr * 10 + 1 < target)
                numbers.push(curr * 10 + 1);
        }
    }

    if (!isReached)
        cout << -1;
    else
        cout << depth;

    return 0;
}