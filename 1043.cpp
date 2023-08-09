#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N, M, truth_num, truth_person;
unordered_set<int> truth_people;
vector<vector<bool>> party;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M;
    party.resize(M + 1, vector<bool>(N + 1, false));

    cin >> truth_num;
    for (int _ = 0; _ < truth_num; _++) {
        cin >> truth_person;
        truth_people.insert(truth_person);
    }

    for (int i = 1; i <= M; i++) {
        int people_num, person;
        
        cin >> people_num;
        for (int _ = 0; _ < people_num; _++) {
            cin >> person;
            party[i][person] = true;
        }
    }

    bool changed;
    do {
        changed = false;
        for (auto truth_person : truth_people) {
            for (int p = 1; p <= M; p++)
                if (party[p][truth_person])
                    for (int person = 1; person <= N; person++)
                        if (party[p][person] && truth_people.find(person) == truth_people.end()) {
                            truth_people.insert(person);
                            changed = true;
                        }
        }
    } while (changed);

    int result = 0;
    for (int p = 1; p <= M; p++) {
        bool revealed = false;
        for (auto truth_person : truth_people)
            if (party[p][truth_person])
                revealed = true;

        if (!revealed) result++;
    }

    cout << result;

    return 0;
}