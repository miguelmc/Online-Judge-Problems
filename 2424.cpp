#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int T, K;
    int socks[16];

    cin >> T;
    for(int j=1; j<=T; j++)
    {
        cin >> K;
        for(int i=0; i<K; i++)
        {
            cin >> socks[i];
        }
        sort(socks, socks+K);

        cout << "Case " << j << ": " << K+1 << " " << socks[K-1]+1 << endl;
    }
    return 0;
}
