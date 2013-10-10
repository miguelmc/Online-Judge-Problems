/*
 * 1959 - Gifts
 * ACCEPTED
 * warning, spaggueti code
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool compPairs(pair<int,int> n1, pair<int,int> n2)
{
    return n1.first + n1.second < n2.first + n2.second;
}

bool compPairs2(pair<int,int> n1, pair<int,int> n2)
{
    return true;
}

int main()
{
    int n, c, i;
    pair<int,int> next, next2;
    cin >> n >> c;
    pair<int,int> arr[n];

    for(i=0; i<n; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr+n, compPairs);

    for(i=0; i<n; i++)
    {
        c -= (arr[i].first + arr[i].second);
        if(c < 0)
            break;
    }
    if(i==n)
    {
        cout << i << endl;
        return 0;
    }
    if(i==0)
    {
        if(arr[0].first/2 + arr[0].second <= c){
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
        return 0;
    }
    c += arr[i].first + arr[i].second;
    next2 = arr[i];

    for(int j=i; j<n; j++)
        arr[j].first  /= 2;

    sort(arr+i, arr+n, compPairs);

    next = arr[i];

    if(c < next.first + next.second)
    {
        --i;
        sort(arr,arr+i-1);
        if(c+arr[i-1].first/2 >= next2.first + next2.second)
            i++;
    }

    cout << i+1 << endl;

    return 0;
}
