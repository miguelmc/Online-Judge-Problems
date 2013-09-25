#include <iostream>
using namespace std;

bool hasAT(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == 'T')
            return true;
    }
    return false;
}

int main()
{
    int t, pos;
    string n, m;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        if(m.find(n) != -1)
        {
            if(hasAT(m))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
        else
            cout << "N" << endl;
    }

    return 0;
}
