/*
 * Accepted
 * time: 609, mem: 436, size: 1850
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool myfunction (int i,int j) { return (i>j); }

bool isvowel(char c){

            return c == 'a' || c == 'e' || c == 'i'
               || c == 'o' || c == 'u';
}

int main(){

    int T, C, vowel, cons;
    cin >> T;
    while(T--)
    {
        vowel = cons = 0;
        cin >> C;
        vector <char> chars;
        char c;
        for(int i=0; i<C; i++){
            cin >> c;
            chars.push_back(c);
            if(isvowel(chars[i]))
                vowel++;
            else cons++;
        }

        if(cons <= 1 || vowel <= 1) {
            cout << -1 << endl;
            continue;
        }

        sort(chars.begin(), chars.end(), myfunction);



        vector<char>::iterator it = chars.begin()+1;
        for(; it != chars.end(); it++){
            if(cons == vowel) break;
            else if(cons > vowel && !isvowel(*it)){
                chars.erase(it);
                cons--;
                it--;
            } else if(vowel > cons && isvowel(*it)){
                chars.erase(it);
                vowel--;
                it--;
            }
        }

        it = chars.begin()+1;
        if(cons%2 != 0) {
            bool v = false, cc = false;
            for(; it != chars.end(); it++){
                if(isvowel(*it) && !v){
                    chars.erase(it);
                    v = true;
                    it--;
                }else if(!isvowel(*it) && !cc){
                    chars.erase(it);
                    cc = true;
                    it--;
                }else if(cc && v)break;
            }
        }



       for(vector<char>::reverse_iterator i = chars.rbegin(); i != chars.rend(); i++)
           cout << *i;
       cout << " " << *chars.begin() - *chars.rbegin() << endl;
    }
    return 0;
}
