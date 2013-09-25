//2425 - Exponent

#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int t, b, e, B, E;
    double max, curr;

    cin >> t;
    while(t != 0){
        cin >> B >> E;
        max = E*log((double)B);
        for(int i=1; i<t; i++)
        {
            cin >> b >> e;
            curr = e*log((double)b);

            if(max < curr){
                max = curr;
                B = b;
                E = e;
            }
        }
        cout << B << " " << E << endl;
        cin >> t;
    }

    return 0;
}
