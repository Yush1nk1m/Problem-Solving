#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;

    vector<string> rooms;

    for (int _ = 0; _ < T; _++)
    {
        int H, W, N;
        cin >> H; cin >> W; cin >> N;
        
        string roomNumber;
        string floorNumber;
        if (N % H != 0)
        {
            roomNumber = to_string(N / H + 1);
            floorNumber = to_string(N % H);
        }
        else
        {
            roomNumber = to_string(N / H);
            floorNumber = to_string(H);
        }
        
        if (roomNumber.length() == 1) roomNumber = "0" + roomNumber;
        roomNumber = floorNumber + roomNumber;
        rooms.push_back(roomNumber);
    }

    for (vector<string>::iterator iter = rooms.begin(); iter != rooms.end(); iter++)
    {
        cout << *iter << endl;
    }

    return 0;
}