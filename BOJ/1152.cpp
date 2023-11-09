#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <set>
using namespace std;

char buf[2000000];
int main()
{
    set<const char*> dict;
    
    scanf("%[^\n]s", buf);
    char* token = strtok(buf, " ");
    while (token)
    {
        token[0] = tolower(token[0]);
        dict.insert(token);
        token = strtok(NULL, " ");
    }

    cout << dict.size();

    return 0;
}