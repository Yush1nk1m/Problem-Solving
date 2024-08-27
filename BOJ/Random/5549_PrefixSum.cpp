/**
 * @file 5549_PrefixSum.cpp
 * @brief 00:33:30
 * @date 2024-08-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

#define JUNGLE  0
#define OCEAN   1
#define ICE     2

int M, N, K;
vector<vector<char>> m;
vector<vector<tuple<int, int, int>>> counts;    // <J, O, I>

inline tuple<int, int, int> tupleAdd(tuple<int, int, int>& t1, tuple<int, int, int>& t2);
inline tuple<int, int, int> tupleSub(tuple<int, int, int>& t1, tuple<int, int, int>& t2);
inline void InitializeMap();
inline tuple<int, int, int> Examine(int r1, int c1, int r2, int c2);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;
    
    InitializeMap();

    while (K--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        tuple<int, int, int> result = Examine(r1, c1, r2, c2);
        cout << get<0>(result) << ' ' << get<1>(result) << ' ' << get<2>(result) << '\n';
    }

    return 0;
}

inline tuple<int, int, int> tupleAdd(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
    return make_tuple(get<0>(t1) + get<0>(t2), get<1>(t1) + get<1>(t2), get<2>(t1) + get<2>(t2));
}

inline tuple<int, int, int> tupleSub(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
    return make_tuple(get<0>(t1) - get<0>(t2), get<1>(t1) - get<1>(t2), get<2>(t1) - get<2>(t2));
}

inline void InitializeMap() {
    m.resize(M + 1, vector<char>(N + 1));
    for (int r = 1; r <= M; r++)
        for (int c = 1; c <= N; c++)
            cin >> m[r][c];

    counts.resize(M + 1, vector<tuple<int, int, int>>(N + 1, make_tuple(0, 0, 0)));
    for (int r = 1; r <= M; r++)
        for (int c = 1; c <= N; c++) {
            switch (m[r][c]) {
                case 'J':
                    counts[r][c] = make_tuple(1, 0, 0);
                    break;
                case 'O':
                    counts[r][c] = make_tuple(0, 1, 0);
                    break;
                case 'I':
                    counts[r][c] = make_tuple(0, 0, 1);
                    break;
            }
            counts[r][c] = tupleAdd(counts[r][c], counts[r][c-1]);
        }
    for (int c = 1; c <= N; c++)
        for (int r = 1; r <= M; r++)
            counts[r][c] = tupleAdd(counts[r][c], counts[r-1][c]);
}

inline tuple<int, int, int> Examine(int r1, int c1, int r2, int c2) {
    tuple<int, int, int> result = counts[r2][c2];
    result = tupleSub(result, counts[r1-1][c2]);
    result = tupleSub(result, counts[r2][c1-1]);
    result = tupleAdd(result, counts[r1-1][c1-1]);
    return result;
}