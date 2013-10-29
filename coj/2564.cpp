/* 
 *  * File:   main.cpp
 *   * Author: Fernando
 *    *
 *     * Created on October 25, 2013, 5:33 PM
 *      */

#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int T;
    unsigned int input;
    bool one, zero;

    scanf("%u", &T);
    for(int i=0; i<T; i++) {
        scanf("%u", &input);
        one = zero = false;
        while(input > 0 && (!one || !zero)) {
            if(input&1) {
                one = true;
            }
            else {
                zero = true;
            }
            input = input>>1;
        }
        if(zero && one)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
