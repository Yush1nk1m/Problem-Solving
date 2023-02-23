#include <iostream>
#include <queue>
using namespace std;
#define min(A, B) A > B ? B : A

typedef long long ll;

int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> pqueue;

    ll N, X;
    cin >> N;
    cin >> X;

    for (ll i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        pqueue.push(temp);
    }

    ll count = 0;
    while (pqueue.size() >= 2)
    {
        ll first, second, result;
        first = pqueue.top();
        pqueue.pop();
        second = pqueue.top();
        pqueue.pop();

        result = min(first + second + (X / 2), X);

        if (result >= X)
        {
            count++;
        }
        else
        {
            pqueue.push(result);
        }
    }
    if (!pqueue.empty())
    {
        ll last = pqueue.top();
        pqueue.pop();

        if (last >= X) count++;
    }

    cout << count;

    return 0;
}