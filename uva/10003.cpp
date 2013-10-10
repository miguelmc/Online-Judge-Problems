//10003 - Cutting Sticks

#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int D[1500][1500];
int d[1500];
int n;

int getThat(int i, int j)
{
    int n = 0;
    for(int k=i; k<=j; k++)
        n += d[k];
    return n;
}

int minimo(int i,int j)
{
    int minimo = INT_MAX;
    for(int k=i; k<=j-1; k++)
    {
       minimo = min(minimo, D[i][k] + D[k+1][j] + getThat(i, j));
    }
    return minimo;
}

int main()
{
    int l;
    cin >> l;
    while(l != 0)
    {
        cin >> n;
        ++n;
        int spots[n+2];
        spots[1] = 0;
        spots[n+1] = l;
        for(int i=2; i<=n; i++)
        {
            cin >> spots[i];
        }
        for(int i=1; i<=n; i++)
        {
            d[i] = spots[i+1] - spots[i];
        }

        for(int i=1; i<=n; i++)D[i][i] = 0;
        for(int diag=1; diag<=n-1; diag++)
        {
            for(int i = 1; i<=n; i++)
            {
                int j = i + diag;
                D[i][j] = minimo(i,j);
            }
        }

        cout << "The minimum cutting is " << D[1][n] << "." << endl;
        cin >> l;
    }

    return 0;
}
