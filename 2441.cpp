//2441 - Dots and Squares

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, r, c, lines;
    cin >> t;
    while(t--)
    {
        cin >> r >> c;
        lines = (r-1)*c + (c-1)*r;
        if(lines%2)
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }

    return 0;
}
