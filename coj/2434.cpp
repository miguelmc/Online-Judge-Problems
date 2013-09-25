#include <iostream>
using namespace std;

long power(int a, int n, int mod)
{
    long power=a,result=1;

    while(n)
    {
        if(n&1) 
            result=(result*power)%mod;
        power=(power*power)%mod;
        n>>=1;
    }
    return result;
}

bool witness(int a, int n)
{
    int t,u,i;
    long prev,curr;

    u=n/2;
    t=1;
    while(!(u&1))
    {
        u/=2;
        ++t;
    }

    prev=power(a,u,n);
    for(i=1;i<=t;++i)
    {
        curr=(prev*prev)%n;
        if((curr==1)&&(prev!=1)&&(prev!=n-1)) 
            return true;
        prev=curr;
    }
    if(curr!=1) 
        return true;
    return false;
}

inline bool IsPrime( int number )
{
    if ( ( (!(number & 1)) && number != 2 ) || (number < 2) || (number % 3 == 0 && number != 3) )
        return (false);

    if(number<1373653)
    {
        for( int k = 1; 36*k*k-12*k < number;++k)
            if ( (number % (6*k+1) == 0) || (number % (6*k-1) == 0) )
                return (false);

        return true;
    }

    if(number < 9080191)
    {
        if(witness(31,number)) return false;
        if(witness(73,number)) return false;
        return true;
    }


    if(witness(2,number)) return false;
    if(witness(7,number)) return false;
    if(witness(61,number)) return false;
    return true;

}

int main()
{
    unsigned long long n, ans;
    cin >> n;
    while(n !=0)
    {
        ans = 1;
        for(int i=1; i<=n; i++)
        {
            if(IsPrime(i))
                ans *= i;
        }
        cout << ans << endl;
        cin >> n;
    }

    return 0;
}
