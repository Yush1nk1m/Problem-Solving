#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        priority_queue<int, vector<int>, greater<int>> min_queue;
        priority_queue<int> max_queue;
        map<int, int> number_map;
        
        int size = 0, num_operation;

        cin >> num_operation;
        for (int __ = 0; __ < num_operation; __++) {
            char cmd;
            int number;

            cin >> cmd;
            cin >> number;

            if (cmd == 'I') {
                size++;
                min_queue.push(number);
                max_queue.push(number);

                if (number_map.find(number) == number_map.end())
                    number_map[number] = 1;
                else number_map[number]++;
            }
            else if (cmd == 'D' && size > 0) {
                size--;

                if (number == 1 && !max_queue.empty()) {
                    while (number_map[max_queue.top()] <= 0) max_queue.pop();

                    number_map[max_queue.top()]--;
                    max_queue.pop();
                }
                else if (number == -1 && !min_queue.empty()) {
                    while (number_map[min_queue.top()] <= 0) min_queue.pop();

                    number_map[min_queue.top()]--;
                    min_queue.pop();
                }
            }
        }

        if (size <= 0) {
            cout << "EMPTY\n";
        }
        else {
            while (number_map[max_queue.top()] <= 0) max_queue.pop();
            while (number_map[min_queue.top()] <= 0) min_queue.pop();

            cout << max_queue.top() << ' ' << min_queue.top() << '\n';
        }
    }

    return 0;
}