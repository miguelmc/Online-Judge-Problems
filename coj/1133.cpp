//1133 - Divisibility by 15
//ACCEPTED
#include <iostream>
#include <algorithm>
using namespace std;

bool descending (int i,int j) { return (i>j); }


int main()
{
    int t, sum, j, remainder, size;
    int isThereA5;
    string s;
    cin >> t;
    while(t--)
    {
        sum = 0;
        cin >> s;
        sort(&s[0], &s[0]+s.size());

        isThereA5 = -1;
        for(int i=0; i<s.size(); i++){
            sum += (s[i]-'0');
            if(s[i] == '5')
                isThereA5 = i;
        }

        if(s[0] != '0')
        {
            if(isThereA5 != -1){
                char temp = s[isThereA5];
                s[isThereA5] = s[0];
                s[0] = temp;
                sort(&s[0] + 1, &s[0]+s.size());
                j = 1;
            }
            else{
                cout << "impossible" << endl;
                continue;
            }
        }
        else
        {
            for(int i=0; i<s.size(); i++){
                if(s[i] != '0'){
                    j=i;
                    break;
                }
            }
        }

        remainder = sum%3;

        //cout << "starts with " << j << "  remainder is " << remainder << " sum is " << sum << endl;

        if(remainder == 0) {
        }

        else {
            bool allGood = false;
            for(int i=j; i<s.size(); i++)
            {
                if( (s[i]-'0')%3 == remainder && !allGood){
                    s.erase(i,1);
                    i--;
                    allGood = true;
                }
            }
            if(!allGood) {
                int count = 2;
                for(int i=j; i<s.size(); i++)
                {
                    if( (s[i]-'0')%3 != remainder && count != 0)
                    {
                        s.erase(i,1);
                        --i;
                        --count;
                    }
                }
            }
        }

        sum = 0;
        for(int i=0; i<s.size(); i++)
            sum += (s[i]-'0');

        if(sum%3 != 0){
            cout << "impossible" << endl;
            continue;
        }

        reverse(&s[0], &s[0]+s.size());
        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i] == '0'){
                s.erase(i,1);
                i--;
            }
            else break;
        }
        cout << s << endl;

    }
    return 0;
}
