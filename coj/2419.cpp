//2419 - Joshua String

#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;

class mycomparison
{
    bool reverse;
    public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const char* lhs, const char*rhs) const
    {
        for(;;)
        {
            if(*rhs == '\0'){
                return false;
            }

            if(*lhs == '\0'){
                return true;
            }

            if(*rhs < *lhs)return true;
            if(*rhs > *lhs)return false;

            rhs++;
            lhs++;
        }
    }
};

int main()
{
    int t, n;
    string *temp;
    string result;

    cin >> t;
    while(t--)
    {
        result = "";
        cin >> n;
        string *arr[n];
        priority_queue<char*,std::vector<char*>,mycomparison> words;
        for(int i=0; i<n; i++)
        {
            temp = new string;
            cin >> *temp;
            arr[i] = temp;
            words.push(&(*temp)[0]);
        }

        while(!words.empty())
        {
            char *curr = words.top();
            words.pop();
            result += *curr;
            curr++;
            if(*curr != '\0')
                words.push(curr);
        }

        cout << result << endl;

        for(int i=0; i<n; i++)
            delete arr[i];
    }

    return 0;
}
