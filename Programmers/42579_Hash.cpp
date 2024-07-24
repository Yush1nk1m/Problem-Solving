/**
 * @file 42579_Hash.cpp
 * @brief 프로그래머스 "베스트앨범"
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Song {
    public:
        int id;
        int played;
        int totalPlayed;
        bool operator<(const Song& s) {
            if (totalPlayed == s.totalPlayed) {
                if (played == s.played)
                    return (id < s.id);
                return (played > s.played);
            }
            return (totalPlayed > s.totalPlayed);
        }
};

map<string, int> m, cnt;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) == m.end())
            m[genres[i]] = plays[i];
        else
            m[genres[i]] += plays[i];
        cnt[genres[i]] = 0;
    }

    vector<Song> song(genres.size());
    for (int i = 0; i < song.size(); i++) {
        song[i].id = i;
        song[i].played = plays[i];
        song[i].totalPlayed = m[genres[i]];
    }
    sort(song.begin(), song.end());

    for (Song& s : song)
        if (cnt[genres[s.id]] < 2) {
            answer.push_back(s.id);
            cnt[genres[s.id]]++;            
        }

    return answer;
}