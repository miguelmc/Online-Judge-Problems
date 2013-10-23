#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n, b, calc, left;
    int * balls;
    bool * done;
    cin >> n >> b;
    while(n != 0 || b != 0)
    {
        balls = new int[n+1];
        done = new bool[n+1];
        memset(done,0,n+1);
        left = n+1;
        for(int i=0; i<b; i++)
            cin >> balls[i];
        for(int i=0; i<b; i++)
        {
            for(int j=0; j<b; j++)
            {
                calc = fabs(balls[i] - balls[j]);
                if(!done[calc])
                {
                    done[calc] = true;
                    --left;
                }
            }
        }
        if(!left)
            cout << "Y" << endl;
        else
            cout << "N" << endl;

        delete[] balls;
        delete[] done;
        cin >> n >> b;
    }
}
