#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long table[1005][1005];
long long D[1005][1005];
int n;

void show()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout << D[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    cin >> n;
    while(n != 0)
    {
        for(int i=0; i<n+5; i++)
        {
            for(int j=0; j<n+5; j++)
            {
                table[i][j] = 0;
                D[i][j] = 0;
            }
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                cin >> table[i][j];
                D[i][j] = table[i][j];
            }
        }

        for(int j=1; j<n; j++)
            for(int i=j; i<=n; i++)
                D[i][j] = D[i][j] + D[i-1][j];


        for(int j=1; j<=n; j++)
        {
            D[n][j] = D[n][j] + D[n-1][j-1];
            for(int i=n-1; i>=j; i--)
            {
                D[i][j] = max(D[i][j] + D[i-1][j-1], D[i+1][j]);

            }
        }

        long long maximum = 0;
        for(int i=1; i<=n; i++)
            maximum = max(maximum, D[i][i]);
        cout << maximum << endl;

        cin >> n;
    }
    return 0;
}
