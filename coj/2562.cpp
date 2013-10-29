#include <iostream>
#include <cmath>
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


bool* Atkins(int max)
{
    //This is the sieve of Atkins.
    bool *primes = new bool[max+1];
    int x, y, n, limit, size;
    size = max+1;
    limit = (int)sqrt(max);
    //Arrays.fill(primes, false);

    primes[0]=false;
    primes[1]=false;
    primes[2]=true;
    if(size>3)
        primes[3]=true;

    for(x=1; x<=limit; x++){
        for(y=1; y<=limit; y++){
            //Equation 1: 4xy + y^2
            n = (4*x*x)+(y*y);
            if(n<=max && (n%12 == 1 || n%12 == 5)){
                primes[n] = !primes[n];
            }
            //Equation 2: 3x^2 + y^2
            n = (3*x*x) + (y*y);
            if(n<=max && (n%12 == 7)){
                primes[n] = !primes[n];
            }
            //Equation 3: 3x^2 - y^2
            n = (3*x*x) - (y*y);
            if(x>y && n<=max && (n%12==11)){
                primes[n]=!primes[n];
            }
        }
    }

    for(n=5; n<=limit; n++){ // Remove all perfect square primes.
        if(primes[n]){
            x = n*n;
            for(y=x; y<=max; y+=x){
                primes[y] = false;
            }
        }
    }
    return primes;
}

int main()
{
    bool * arr = Atkins(1000000);
    int n, pow, i;

    while(cin >> n)
    {
        i = 2;
        //for(int i = 2; !IsPrime(n); i++)
        while(n != 1)
        {
            pow = 0;
            if(arr[i])
            {
                while(n%i==0)
                {
                    n /= i;
                    //cout << n << endl;
                    ++pow;
                }
                if(pow != 0)
                cout << "("<< i << "(" << pow << "))";
            }
            i++;
        }
        cout << endl;
    }

    return 0;
}
