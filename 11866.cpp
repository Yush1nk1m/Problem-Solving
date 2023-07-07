#include <iostream>
#include <queue>
using namespace std;

queue<int> circle;
int N, K;

int main(int argc, char* argv[]) {
    cin >> N >> K;

    for (int i = 1; i <= N; i++) circle.push(i);

    cout << '<';
    int turn = 0;
    while (circle.size() > 1) {
        turn++;
        int temp = circle.front();
        circle.pop();
        if (turn % K != 0) circle.push(temp);
        else cout << temp << ", ";
    }
    cout << circle.front() << '>';

    return 0;
}