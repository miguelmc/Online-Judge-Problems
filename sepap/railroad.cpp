#include <iostream>
using namespace std;

int main()
{
    int n1, n2, *arr1, *arr2, *result, *temp1, *temp2;
    cin >> n1 >> n2;
    while(n1 || n2)
    {
        arr1 = new int[n1+1];
        arr2 = new int[n2+1];
        result = new int[n1+n2];
        for(int i=0; i<n1; i++)
            cin >> arr1[i];
        for(int i=0; i<n2; i++)
            cin >> arr2[i];
        arr1[n1] = arr2[n2] = -1;
        for(int i=0; i<n1+n2; i++)
            cin >> result[i];

        while(*arr1 != -1 || *arr2 != -1)
        {
            if(*arr1 == *result && *arr2 != *result)
            {
                ++arr1;
                ++result;
            }
            else if(*arr2 == *result && *arr1 != *result)
            {
                ++arr2;
                ++result;
            }
            else if(*arr1 == *result && *arr2 == *result)
            {
                temp1 = arr1;
                temp2 = arr2;
                while(*temp1 == *result && *temp2 == *result)
                {
                    ++temp1;
                    ++temp2;
                    ++result;
                }
                if(*temp1 == *result)
                {
                    arr1 = temp1;
                }
                else if(*temp2 == *result)
                {
                    arr2 = temp2;
                }
                else if(*temp1 == -1 && *temp2 == -1)
                    arr1 = temp1;
                else if(*temp1 != -1 && *temp2 != -1)
                {
                    arr1 = temp1;
                    arr2 = temp2;
                }
                else if(*temp1 == -1)
                    arr1 = temp1;
                else
                    arr2 = temp2;
            }
            else
                break;
        }

        if(*arr1 == -1 && *arr2 == -1)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;

        cin >> n1 >> n2;
    }
    return 0;
}
