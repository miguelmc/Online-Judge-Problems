//2244 - Dream with Numbers

#include <iostream>
#include <cstring>
using namespace std;

int zeros;
int arr[10];

void getZeros(string s)
{
    memset(arr, 0, 10*sizeof(int));
    for(int i=0; i<s.size(); i++)
    {
        arr[s[i]-'0'] += 2;
    }

    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;

    zeros = arr[0]/2;
    for(int i=1; i<=5; i++)
    {
        if(arr[i] && arr[10-i])
        {
            ++zeros;
            --arr[i];
            --arr[10-i];
            break;
        }
    }
    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;
    for(int i=1; i<=4; i++)
    {
        if(arr[i] && arr[9-i])
        {
            ++zeros;
            --arr[i];
            --arr[9-i];
        }
    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;
    }
    for(int i=2; i<=4; i++)
    {
        if(arr[i] && arr[10-i])
        {
            ++zeros;
            --arr[i];
            --arr[10-i];
        }
    for(int i=0;i<10;i++)
        cout << arr[i] << " ";
    cout << endl;
    }

}

int main()
{
    int t;
    string n1, n2;
    cin >> t;
    while(t--)
    {
        cin >> n1;
        n2 = n1;
        zeros = 0;
        getZeros(n1);
        cout << zeros << endl;
    }

    return 0;
}
