#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int N, x, y, xi, yi, r, index;
    double minDistance, temp;
    cin >> N;
    while(N != 0)
    {
        cin >> x >> y;

        cin >> xi >> yi >> r;
        index = 0;
        minDistance = sqrt(pow((double)x-(double)xi,2) + 
                    pow((double)y-(double)yi,2)) - (double)r;

        for(int i=1; i<N; i++){
            cin >> xi >> yi >> r;
            temp = sqrt(pow((double)x-(double)xi,2) + 
                            pow((double)y-(double)yi,2)) - (double)r;
            if(temp < minDistance)
            {
                minDistance = temp;
                index = i;
            }
        }

        cout << (index+1) << endl;
        cin >> N;
    }
    return 0;
}
