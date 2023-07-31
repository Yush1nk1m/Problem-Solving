#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int T, n;
    string p, line;
    
    cin >> T;
    for (int _ = 0; _ < T; _++) {
        cin >> p;
        cin >> n;
        cin >> line;
        istringstream iss(line);

        char temp;
        int element;
        iss >> temp;    // '[' 제거
        
        deque<int> arr;
        for (int i = 0; i < n; i++) {
            iss >> element;     // 원소 추출
            iss >> temp;        // ',' 제거

            arr.push_back(element);
        }

        bool is_forward = true;
        bool is_valid = true;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') {
                is_forward = !is_forward;
            }
            else if (p[i] == 'D') {
                if (arr.size() == 0) {
                    is_valid = false;
                    break;
                }
                
                if (is_forward) arr.pop_front();
                else arr.pop_back();
            }
        }

        if (is_valid) {
            if (arr.size() > 0) {
                cout << '[';
                if (is_forward) {
                    for (int i = 0; i < arr.size() - 1; i++) {
                        cout << arr[i] << ',';
                    }
                    cout << arr[arr.size() - 1] << "]\n";
                }
                else {
                    for (int i = arr.size() - 1; i > 0; i--) {
                        cout << arr[i] << ',';
                    }
                    cout << arr[0] << "]\n";
                }
            }
            else {
                cout << "[]\n";
            }
        }
        else {
            cout << "error\n";
        }
    }
}