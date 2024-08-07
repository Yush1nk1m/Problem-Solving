/**
 * @file 2148_Implementation.cpp
 * @brief 01:05:28
 * @date 2024-08-07
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Rank {
    public:
        Rank() {}
        Rank(string name) {
            this->name = name;
            this->point = 0;
            this->score = 0;
            this->scoreAgainst = 0;
            this->tries = 0;
            this->triesAgainst = 0;
        }
        string name;
        int point;
        int score;
        int scoreAgainst;
        int tries;
        int triesAgainst;
        bool operator<(const Rank& r) const {
            if (point == r.point) {
                if ((score - scoreAgainst) == (r.score - r.scoreAgainst)) {
                    if (tries == r.tries) {
                        return (name < r.name);
                    }
                    return (tries > r.tries);
                }
                return (score - scoreAgainst) > (r.score - r.scoreAgainst);
            }
            return (point > r.point);
        }
};

int r = 1;
string input;
map<string, Rank> m;
map<string, bool> played;

inline void PrintBoard(int r);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> input) {
        if (input == "#")
            break;
        m.insert({ input, Rank(input) });
        m[input].name = input;
        played[input] = false;
    }

    while (1) {
        string team1, team2;
        int homeScore, awayScore, homeTries, awayTries;
        
        cin >> team1;
        if (team1 == "#")
            break;
        cin >> team2 >> homeScore >> awayScore >> homeTries >> awayTries;

        if (homeScore > awayScore) {
            m[team1].point += 4;
            if (homeScore - 8 <= awayScore)
                m[team2].point++;
        } else if (homeScore < awayScore) {
            m[team2].point += 4;
            if (awayScore - 8 <= homeScore)
                m[team1].point++;
        } else {
            m[team1].point += 2;
            m[team2].point += 2;
        }
        if (homeTries >= 4)
            m[team1].point++;
        if (awayTries >= 4)
            m[team2].point++;

        m[team1].score += homeScore;
        m[team1].scoreAgainst += awayScore;
        m[team1].tries += homeTries;
        m[team1].triesAgainst += awayTries;

        m[team2].score += awayScore;
        m[team2].scoreAgainst += homeScore;
        m[team2].tries += awayTries;
        m[team2].triesAgainst += homeTries;

        played[team1] = played[team2] = true;

        bool finishedRound = true;
        for (auto it = played.begin(); it != played.end(); it++)
            if (it->second == false) {
                finishedRound = false;
                break;
            }
        if (finishedRound) {
            PrintBoard(r++);
            for (auto it = played.begin(); it != played.end(); it++)
                played[it->first] = false;
        }
    }

    return 0;
}

inline void PrintBoard(int r) {
    vector<Rank> teams;
    for (auto it = m.begin(); it != m.end(); it++)
        teams.push_back(it->second);
    sort(teams.begin(), teams.end());

    cout << "Round " << r << '\n';
    for (Rank& team : teams) {
        cout << left << setw(21) << team.name;
        cout << right << setw(2) << team.point;
        cout << right << setw(4) << team.score;
        cout << right << setw(4) << team.scoreAgainst;
        cout << right << setw(3) << team.tries;
        cout << right << setw(3) << team.triesAgainst << '\n';
    }
    cout << '\n';
}