#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;

static bool visited[1000001];
static vector<int> cards;
static vector<int> scores;
static unordered_map<int, int> players;

inline void CalcScore(int player);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numPlayers;
    cin >> numPlayers;

    cards.resize(numPlayers);
    scores.resize(numPlayers, 0);

    for (int i = 0; i < numPlayers; i++) {
        cin >> cards[i];
        players[cards[i]] = i;
        visited[cards[i]] = true;
    }

    for (int player = 0; player < numPlayers; player++)
        CalcScore(player);

    for (int score : scores)
        cout << score << ' ';

    return 0;
}

inline void CalcScore(int player) {
    int score = 0;
    int number = cards[player];
    unordered_set<int> divisors;

    for (int divisor = 1; divisor <= sqrt(number); divisor++) {
        if (number % divisor == 0) {
            if (visited[divisor])
                divisors.insert(divisor);
            if (visited[number / divisor])
                divisors.insert(number / divisor);
        }
    }

    for (int divisor : divisors) {
        int opponent = players[divisor];
        scores[opponent]++;
        scores[player]--;
    }

}