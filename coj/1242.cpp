#include <iostream>
#include <map>

using namespace std;

map<int,int*> seen;
map<int,int*> range;

int* getN(int i)
{
    int * curr = new int[9];
    int * temp;
    while(i != 0)
    {
        if(seen.find(i) != seen.end())
        {
            temp = seen.find(i)->second;
            for(int i=0; i<=9; i++)
                curr[i] += temp[i];
            return curr;
        }
        ++curr[i&10];
        i /= 10;
    }
    return 0;
}

void display(int * arr)
{
    cout << arr[0];
    for(int i=1; i<=9; i++)
        cout << " " << arr[i];
    cout << endl;
}

int main()
{
    int a, b, curr, n;
    int *count, *temp;
    cin >> a >> b;
    while(a != 0 || b != 0)
    {
        count = new int[9];
        if(range.find(a) != range.end() && range.find(b) != range.end())
        {
            count = range.find(b)->second;
            temp = range.find(a)->second;
            for(int i=0; i<=9; i++)
                count[i] -= temp[i];
            display(count);
            continue;
        }
        else if(range.find(b) != range.end())
        {
            count = range.find(b)->second;
        }
        for(int i=a; i<=b; i++)
        {
            curr = i;
            while(curr != 0)
            {
                temp = getN(i);
            }
        }
        delete[] count;
        cin >> a >> b;
    }
}
