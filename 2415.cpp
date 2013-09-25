#include <math.h>
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
using namespace std;



int main(){
    int T, N, R, H;
    double volume;
    cin >> T;
    while(T--){
        volume = 0;
        cin >> N;
        while(N--)
        {
            cin >> R >> H;
            volume += R*R*M_PI*H;
        }
        cout << setprecision(2) << fixed << volume << endl;
    }
}
