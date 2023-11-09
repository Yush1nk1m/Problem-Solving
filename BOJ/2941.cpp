#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);

    int count = 0;
    int index = 0;
    while (index < line.length())
    {
        switch (line[index])
        {
            case 'd':   if (line[index + 1] == 'z' && line[index + 2] == '=')
                        {
                            count++;
                            index += 3;
                            break;
                        }
            case 'c':   if (line[index + 1] == '-')
                        {
                            count++;
                            index += 2;
                            break;
                        }
            case 's':
            case 'z':   if (line[index + 1] == '=')
                        {
                            count++;
                            index += 2;
                            break;
                        }
                        count++;
                        index++;
                        break;
            case 'l':
            case 'n':   if (line[index + 1] == 'j')
                        {
                            count++;
                            index += 2;
                            break;
                        }
                        count++;
                        index++;
                        break;
            default:    count++;
                        index++;
                        break;
        }
    }

    cout << count;

    return 0;
}