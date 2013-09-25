// 2439 - Fractal

#include <iostream>
#include <math.h>
using namespace std;

int main() {

    int l, t, s, n;
    double curr;
    cin >> t;
    while(t--)
    {
        n = 0;
        cin >> l >> s;
        curr = l;

        while(curr <= s){
            ++n;
            curr = (l/pow(3,n))*pow(5, n);
        }

        cout << n-1 << endl;
    }

    return 0;
}
