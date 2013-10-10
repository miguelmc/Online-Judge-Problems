//1131 - Divisors

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;

unsigned long long c[432][432];
unsigned long long d[432][432];
map <unsigned long long, unsigned long long> primeFactor;

void atkin()
{
    //Create the various different variables required
    int limit = 1000000;
    int root = ceil(sqrt(limit));
    bool sieve[limit];
    //int primes[(limit/2)+1];
    int insert = 2;
    primeFactor[2] = 0;
    primeFactor[3] = 0;
    for (int z = 0; z < limit; z++) sieve[z] = false; //Not all compilers have false as the default boolean value
    for (int x = 1; x <= root; x++)
    {
        for (int y = 1; y <= root; y++)
        {
            //Main part of Sieve of Atkin
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) sieve[n] ^= true;
            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7) sieve[n] ^= true;
            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11) sieve[n] ^= true;
        }
    }
    //Mark all multiples of squares as non-prime
    for (int r = 5; r <= root; r++) if (sieve[r]) for (int i = r*r; i < limit; i += r*r) sieve[i] = false;
    //Add into prime array
    for (int a = 5; a < limit; a++)
    {
        if (sieve[a])
        {
            primeFactor[a] = 0;
        }
    }
}

unsigned long long compute(unsigned long long x)
{
    map<unsigned long long, unsigned long long> primes;
    map<unsigned long long, unsigned long long>::iterator it;
    for(it=primeFactor.begin(); it != primeFactor.end(); it++) {
        primes[it->first] = it->second;
    }
    while(x > 1) {
        for(it=primes.begin(); it != primes.end() && it->first <= x; it++) {
            if(x % it->first == 0) {
                x = x / it->first;
                it->second = it->second +1;
            }
        }
    }

    unsigned long long result = 1;
    for(it=primes.begin(); it != primes.end(); it++) {
          result *= (it->second+1);
    }
    return result;
}

unsigned long long getnumdivisors(unsigned long long n)
{
    if(n == 1)
        return 1;
    int div = 2;
    for(unsigned long long i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
            div += 2;
    }
    return div;
}

int main()
{
    unsigned long long n, k, curr = 2, result;
    memset(c, 0, 432*432*sizeof(long long));
    memset(d, 0, 432*432*sizeof(long long));
    c[0][0] = d[0][0] = 1;
    c[1][1] = d[1][1] = 1;
    c[1][0] = d[1][0] = 1;

    atkin();
    while(cin >> n >> k)
    {
        if(d[n][k] > 0)
        {
            cout << d[n][k] << endl;
            continue;
        }

        if(curr < n)
        {
            for(int i=curr; i<=n; i++)
            {
                d[i][i] = c[i][i] = 1;
                d[i][i] = c[i][0] = 1;
            }

            for(int i=curr; i<=n; i++)
            {
                for(int j=1; j<i; j++)
                {
                    c[i][j] = c[i-1][j] + c[i-1][j-1];
                }
            }
            curr = n;
        }

        /*for(int i=0; i<=n; i++)
          {
          for(int j=0; j<=i; j++)
          {
          cout << c[i][j] << " ";
          }
          cout << endl;
          }*/

        result = compute(c[n][k]);
        d[n][k] = result;
        cout << result << endl;
    }

    return 0;
}
