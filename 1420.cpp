#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    cout << (142/2^76) << endl;
    int s, a, x, y;
    while(cin >> s >> a){
        for(x=0; x<10000;x++){
            y = s - x;
            if(x^y == a)
                break;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
