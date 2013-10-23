#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long table[1005][1005];
long long dinamic[1005][1005];
long long solution[1005][1005];

int getThat(int i,int j)
{
    if(j-i == 1)return dinamic[i][j];
    int n=0;
    for(int a=0; a<=i; a++)
    {
        n+=dinamic[i-a][j-a];
    }
    return n;
}

int maximo(int i, int j)
{
    int maximo = INT_MIN;
    for(int k=i; k<=j-1; k++)
    {
        maximo = max((long long)maximo, solution[i][k] + solution[k+1][j] + getThat(i, j));
    }
    return maximo;
}

int main()
{
    int n, temp;
    cin >> n;
    while(n != 0)
    {
        for(int i=0; i<=n+5; i++)
        {
            table[i][i] = 0;
            dinamic[i][i] = 0;
            solution[i][i] = 0;
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<=i; j++)
                cin >> table[j][i];

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                dinamic[i][j + 1] = table[i][j] + dinamic[i][j];



        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
                cout << table[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
                cout << dinamic[i][j] << "\t";
            cout << endl;
        }
        cout << endl;

        for(int diag=1; diag<=n; diag++)
        {
            for(int i=0; i<=n-diag; i++)
            {
                int j= i + diag;
                cout << i << " " << j << endl;
                solution[i][j] = maximo(i,j);
            }
        }

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
                cout << solution[i][j] << "\t";
            cout << endl;
        }
        cin >> n;
    }
    return 0;
}
