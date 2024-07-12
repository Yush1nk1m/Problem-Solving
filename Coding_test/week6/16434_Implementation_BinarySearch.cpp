/**
 * @file 16434_Implementation_BinarySearch.cpp
 * @brief 00:56:14
 * @date 2024-07-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MONSTER 1
#define POTION  2

class Player {
    public:
        ll maxHP;
        ll curHP;
        ll atk;
};

class Room {
    public:
        ll type;
        ll atk;
        ll hp;
};

int N;
ll initAtk, low = 1, high = 1e6 * 1e6 * 123456 + 1, result;
vector<Room> room;

inline bool Simulation(ll maxHP);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> initAtk;
    room.resize(N);
    for (int i = 0; i < N; i++)
        cin >> room[i].type >> room[i].atk >> room[i].hp;
    
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (Simulation(mid)) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}


inline bool Simulation(ll maxHP) {
    Player player;
    player.maxHP = player.curHP = maxHP;
    player.atk = initAtk;

    for (Room& r : room) {
        if (r.type == MONSTER) {
            ll monHP = r.hp, monAtk = r.atk;
            ll turn = min(monHP / player.atk, player.curHP / monAtk);
            if (turn)
                turn--;
            
            monHP -= (turn * player.atk);
            player.curHP -= (turn * monAtk);

            while (1) {
                monHP -= player.atk;
                if (monHP <= 0) break;

                player.curHP -= monAtk;
                if (player.curHP <= 0)
                    return false;
            }
        } else if (r.type == POTION) {
            player.curHP = min(player.curHP + r.hp, player.maxHP);
            player.atk += r.atk;
        }
    }

    return true;
}