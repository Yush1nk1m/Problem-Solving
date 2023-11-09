#include <iostream>
#include <vector>
using namespace std;

int N, d, k, c;
int l, r;
int kind, max_kind;

vector<bool> sushiset;
vector<int> sushitable;

inline bool isSet(int kind) {
    return sushiset[kind];
}

inline void set(int kind) {
    sushiset[kind] = true;
}

inline void reset(int kind) {
    sushiset[kind] = false;
}

inline int setsize() {
    int result = 0;
    
    for (int i = 1; i <= d; i++)
        if (isSet(i)) result++;
    
    return result;
}

int main(int argc, char* argv[]) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> d >> k >> c;

    sushitable.resize(N);
    sushiset.resize(d + 1);

    for (int i = 0; i < N; i++)
        cin >> sushitable[i];
    
    for (r = 0; r < k; r++) {
        if (!isSet(sushitable[r])) {
            set(sushitable[r]);
        }
    }
    
    if (!isSet(c))
        set(c);

    max_kind = setsize();

    for (int _ = 0; _ < N; _++) {
        if (isSet(sushitable[l])) {
            reset(sushitable[l]);
        }
        
        l = (l + 1) % N;

        r = (r + 1) % N;

        for (int p = l; p != r; p = (p + 1) % N)
            set(sushitable[p]);
        
        set(c);
        
        kind = setsize();

        if (max_kind < kind)
            max_kind = kind;
    }

    cout << max_kind;

    return 0;
}