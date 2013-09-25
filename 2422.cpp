// 2422 - Betty and the Modular Exponentiation

#include <iostream>
#define MOD 1000000000

using namespace std;

//exponenciacion logaritmica de un numero a elevado a la b (recursivo)
long long pot( long long a, long long b){
    long long r;
    if( b == 0 ) return 1;
    if( b == 1 ) return a % MOD;
    r = pot( a , b / 2);
    r = (r * r ) % MOD;
    if(b % 2 == 1) r = (r * a) % MOD;
    return r;
}

int main()
{
    int t, aaa;
    unsigned long long a, b, temp;
    cin >> t;
    bool first = true;
    while(t--)
    {
        cin >> a >> b;

        cout << pot(a,b) << endl;
    }
}
