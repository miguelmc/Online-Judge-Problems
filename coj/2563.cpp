#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int open = 0;
    string l;
    char *line, *result, *ptr;
    result = ptr = (char*)malloc(1005*sizeof(char));
    while(getline(cin, l))
    {
        line = &l[0];
        ptr = result;
        while(*line != '\0')
        {
            if(*line == '#' && *(line+1) == '@')
            {
                ++open;
                line += 2;
            }
            else if(*line == '@' && *(line+1) == '#')
            {
                --open;
                line += 2;
            }
            else if(!open)
            {
                *ptr = *line;
                ++ptr;
                ++line;
            }
            else
                ++line;
        }
        *ptr = '\0';
        cout << result << endl;

    }
}
