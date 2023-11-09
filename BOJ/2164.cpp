#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> cards;

int main(int argc, char* argv[]) {
    cin >> N;

    for (int card = 1; card <= N; card++)
        cards.push(card);
    
    int front;
    while (cards.size() > 1) {
        cards.pop();
        front = cards.front();
        cards.push(front);
        cards.pop();
    }

    cout << cards.front();

    return 0;
}