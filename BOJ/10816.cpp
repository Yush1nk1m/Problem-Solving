#include <iostream>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;
    
    map<int, int> cards;
    int card;

    for (int _ = 0; _ < N; ++_)
    {
        cin >> card;
        if (cards.find(card) == cards.end())
        {
            cards.insert(pair<int, int>(card, 1));
        }
        else
        {
            ++cards[card];
        }
    }

    int M;
    cin >> M;
    for (int _ = 0; _ < M; ++_)
    {
        cin >> card;
        cout << cards[card] << ' ';
    }

    return 0;
}