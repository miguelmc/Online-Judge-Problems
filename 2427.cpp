#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


long long int power(int a, int n, int mod)
{
    long long int power=a,result=1;

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
    long long int prev,curr;

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
    int a, b, n, i, size;
    int test[1000001];
    n=0;
    for(int i=2; i<1000001; i++)
    {
        if(IsPrime(i))
            n++;
        test[i] = n;
        //test[i] = -1;
    }
    cin >> a >> b;
    while(a != 0 || b != 0)
    {
        n = 0;
        if(test[a] >= 0 && test[b] >= 0)
        {
            n = test[b] - test[a-1];
        }
        else if(test[a] >= 0)
        {
            i = a;
            while(test[i] >= 0)
                ++i;
            n = test[i-1] - test[a];
            for(int j=i; j<=b; j++)
            {
                if(IsPrime(j))
                {
                    ++n;
                }
                test[j] = n;
            }
        }
        else if(test[b] >= 0)
        {
            i = b;
            while(test[i] >= 0)
                --i;
            n = test[b] - test[i+1];
            for(int j=a; j<=i; j++)
            {
                if(IsPrime(j) >= 0)
                {
                    ++n;
                }
                test[j] = n;
            }
        }
        else
        {
            for(int j=a; j<=b; j++)
            {
                if(IsPrime(j))
                {
                    ++n;
                }
                else test[j] = n;
            }
        }

        cout << n << endl;
        cin >> a >> b;
    }
    return 0;
}
