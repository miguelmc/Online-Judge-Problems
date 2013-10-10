#include <iostream>
#include <limits.h>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int t, n, u, v, d;
    scanf("%i", &t);
    while(t--)
    {
        scanf("%i",&n);
        int paths[n+1][n+1];

        //--------FLOYD'S ALGORITHM-O(n^3)------------------------
        for(int i = 1; i<=n; i++)
        {
            for(int j=i; j<=n; j++)
            {
                if(i==j)
                    paths[j][i] = paths[i][j] = 0;
                else
                    paths[j][i] = paths[i][j] = INT_MAX/2;
            }
        }
        for(int i = 1; i<n; i++)
        {
                scanf("%i%i%i",&u,&v,&d);
                paths[v][u] = paths[u][v] = d;
        }

        int planeta = 0;
        int maximo;
        int minimo = INT_MAX;
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                maximo = -1;
                for(int j=1; j<=n; j++)
                {
                    paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
                    maximo = max(maximo, paths[i][j]);
                }
                if(k==n && minimo > maximo)
                {
                    minimo = maximo;
                    planeta = i;
                }
            }
        }
        //---------------------------------------------------

        printf("%i %i\n", planeta, minimo);

        /*for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout << paths[i][j] << "\t";
            cout << endl;
        }*/
    }

    return 0;
}
