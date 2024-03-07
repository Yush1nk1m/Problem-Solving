#include <iostream>
#include <vector>
using namespace std;

bool CheckCapacity(vector<int>& videos, int bluray_size, int bluray_number);

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // upperbound = sum of the values, lowerbound = max value
    int upperbound = 0, lowerbound = 0;

    vector<int> videos(N);
    for (int i = 0; i < N; i++) {
        cin >> videos[i];
        upperbound += videos[i];
        if (lowerbound < videos[i]) lowerbound = videos[i];
    }
    
    int result = upperbound;
    do {
        int mid = (lowerbound + upperbound) / 2;
        bool isValid = CheckCapacity(videos, mid, M);

        if (isValid) {
            result = mid;
            upperbound = mid - 1;
        } else {
            lowerbound = mid + 1;
        }
    } while (lowerbound <= upperbound);

    cout << result;

    return 0;
}

bool CheckCapacity(vector<int>& videos, int bluray_size, int bluray_number) {
    int curr_size = 0;
    int bluray_counter = 1;
    
    for (int i = 0; i < videos.size() && bluray_counter <= bluray_number; i++) {
        if (videos[i] > bluray_size) return false;

        if (videos[i] + curr_size > bluray_size) {
            curr_size = videos[i];
            bluray_counter++;
        }
        else
            curr_size += videos[i];
    }

    if (bluray_counter <= bluray_number) return true;
    else return false;
}