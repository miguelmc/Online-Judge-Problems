#include <iostream>
using namespace std;

int main()
{
    long n, ans;
    cin >> n;
    while(n != 0)
    {
        ans = 1;
        for(long i=1; n>i; i+=2)
        {
            n-=i;
            ++ans;
        }

        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
