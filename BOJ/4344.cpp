#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    
    int C;
    cin >> C;
    vector<double> rate(C);

    for (int i = 0; i < C; i++)
    {
        int N;
        cin >> N;

        vector<int> ptr(N);

        double avg = 0.0;
        for (int j = 0; j < N; j++)
        {
            int score;
            cin >> score;
            avg += static_cast<double>(score);
            ptr[j] = score;
        }
        avg /= static_cast<double>(N);
        
        int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (ptr[j] > avg) count++;
        }

        rate[i] = (static_cast<double>(count) / static_cast<double>(N));
    }

    for (int i = 0; i < C; i++)
    {
        cout << setprecision(3) << fixed << rate[i] * 100 << "%" << endl;
    }
    return 0;
}