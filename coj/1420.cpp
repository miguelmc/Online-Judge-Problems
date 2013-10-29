#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    long long s, a;
    int x, y;
    while(cin >> s >> a){

        cout << "hola" << endl;
        //cout << a << " " << s << " " << (a-s) << endl;
        if(a>s)
            y = (a-s)/(-2);
        else
            y=(s-a)/(2);
        x = s-y;

        //cout << x << " " << y << " " << s << " " << a << endl;
        if((x+y) == s && (x^y)==a)
            if(x>y){
                cout << y << " " << x << endl;
            }
            else
                cout << y << " " << x << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}


