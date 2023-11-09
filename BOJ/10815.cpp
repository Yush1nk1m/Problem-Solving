#include <iostream>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin >> N;

    set<int> cards;
    int card;
    for (int _ = 0; _ < N; ++_)
    {
        cin >> card;
        cards.insert(card);
    }

    int M;
    cin >> M;
    for (int _ = 0; _ < M; ++_)
    {
        cin >> card;
        if (cards.find(card) != cards.end())
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }

    return 0;
}