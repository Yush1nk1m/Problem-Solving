#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int T, N;
    string MBTI;

    cin >> T;

    for (int _ = 0; _ < T; _++) {
        cin >> N;
        
        int min_distance = 999;
        
        if (N <= 32) {
            vector<vector<int>> distances(N, vector<int>(N, 0));
            vector<bitset<4>> mbti_set(N, bitset<4>(0));

            for (int i = 0; i < N; i++) {
                cin >> MBTI;

                mbti_set[i][0] = (MBTI[0] == 'E');
                mbti_set[i][1] = (MBTI[1] == 'N');
                mbti_set[i][2] = (MBTI[2] == 'T');
                mbti_set[i][3] = (MBTI[3] == 'P');
            }

            for (int i = 0; i < N; i++) {
                for (int j = i; j < N; j++) {
                    bitset<4> dist = mbti_set[i] ^ mbti_set[j];

                    distances[i][j] = dist.count();
                    distances[j][i] = dist.count();
                }
            }

            
            for (int first = 0; first < N; first++) {
                for (int second = first + 1; second < N; second++) {
                    for (int third = second + 1; third < N; third++) {
                        if (distances[first][second] + distances[second][third] + distances[third][first] < min_distance)
                            min_distance = distances[first][second] + distances[second][third] + distances[third][first];
                    }
                }
            }
        }
        else {
            for (int i = 0; i < N; i++) cin >> MBTI;
            min_distance = 0;
        }
        
        cout << min_distance << '\n';
    }

    return 0;
}