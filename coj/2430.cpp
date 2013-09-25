#include <iostream>
#include <math.h>
using namespace std;

bool isTriangular(long double n)
{
    long double temp = sqrt(n*2+.25)-.5;
    return temp == floor(temp);
}
bool isTriangular2(unsigned long long n)
{
    unsigned long long calc = 8*n+1;
    unsigned long long t = (unsigned long long) sqrt(calc);
    if (t*t==calc) {
        return true;
    }
    return false;
}

int main()
{
    unsigned long long n;
    cin >> n;
    while(n != 0){
        cout << (isTriangular2(n) ? "YES" : "NO") << endl;
        cin >> n;
    }
}
