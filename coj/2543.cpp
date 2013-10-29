#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int gcdr ( int a, int b )
{
      if ( a==0 ) return b;
        return gcdr ( b%a, a );
}

int main()
{
    int n, k, p;
    while(cin >> n >> k >> p)
    {
        int arr[n];
        int arr2[n];
        for(int i=0; i<n; i++)
        {
            cin >> arr[i];
            arr2[i] = i>=n-k;
        }
        int c = 0;
        do{
            c += 1!=gcdr(inner_product(arr2, arr2+n, arr, 0), p);

        }while(next_permutation(arr2, arr2+n));
        cout << c << endl;
    }
}
