//2432 - Simple Median

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main(){

    priority_queue<int> *nums;
    int t, n;
    double median;

    cin >> t;
    while(t != 0){
        nums = new priority_queue<int>;
        for(int i=0; i<t; i++)
        {
            cin >> n;
            nums->push(n);
        }


        int s = nums->size();
        for(int i=0; i<s/2-1; i++)
            nums->pop();

        if(s%2) {
            nums->pop();
            median = (double)nums->top();
        }
        else {
            median = (double)nums->top();
            nums->pop();
            median += (double)nums->top();
            median /= 2.0;

        }
        cout << setprecision(1) << fixed  << median << endl;

        delete nums;
        cin >> t;
    }

    return 0;
}
