#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll N, M;
    cin >> N;
    cin >> M;

    ll** matrix1;
    ll** matrix2;
    matrix1 = new ll*[N];
    matrix2 = new ll*[N];
    for (ll i = 0; i < N; i++)
    {
        matrix1[i] = new ll[M];
        matrix2[i] = new ll[M];
    }

    for (ll r = 0; r < N; r++)
    {
        for (ll c = 0; c < M; c++)
        {
            cin >> matrix1[r][c];
        }
    }

    for (ll r = 0; r < N; r++)
    {
        for (ll c = 0; c < M; c++)
        {
            cin >> matrix2[r][c];
            matrix1[r][c] += matrix2[r][c];
        }
    }

    for (ll r = 0; r < N; r++)
    {
        for (ll c = 0; c < M; c++)
        {
            cout << matrix1[r][c] << " ";
        }
        cout << endl;
    }

    for (ll i = 0; i < N; i++)
    {
        delete[] matrix1[i];
        delete[] matrix2[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    return 0;
}