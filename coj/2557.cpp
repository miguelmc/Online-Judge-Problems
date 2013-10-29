#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

bool cmp(int n1, int n2)
{
    return n1 > n2;
}

int main()
{
    int s, i, j, size, minimum, temp, wins = 0;
    int *q,* n;
    cin >> s;
    q = new int[s];
    n = new int[s];
    minimum = INT_MAX;
    for(int i=0; i<s; i++){
        cin >> q[i];
        minimum = min(q[i], minimum);
    }
    size = 0;
    for(int i=0; i<s; i++)
    {
        cin >> temp;
        if(temp > minimum)
        {
            n[size] = temp;
            ++size;
        }
    }


    sort(q, q+s);
    sort(n, n+size);

    i=0;
    for(i=0; i<size; i++)
    {
        if(n[i] > q[i])
        {
            ++wins;
        }
        else if(n[i] == q[i])
            continue;
        else break;
    }
    cout << wins << endl;

    return 0;
}
