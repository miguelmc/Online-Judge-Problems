#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cstring>
#include <math.h>
using namespace std;

int nums[1000001];

bool hasEvenDigit(int x) {
   bool evenFound = false;

   do {
      evenFound = !((x % 10) & 1);
   } while ((evenFound == false) && ((x /= 10) > 0));

   return evenFound;
}

void populate(){
   int count = 0;
   for(int i=1; i<=1000000;i++)
   {
      if(hasEvenDigit(i))
         ++count;
      nums[i] = count;
   }
}

int find(string a, string b)
{
   int A = atoi(a.c_str());
   int B = atoi(b.c_str());

   return nums[B] - nums[A-1];
}

int main(){
   int t;
   string a, b;
   cin >> t;
   populate();
   while(t--)
   {
      cin >> a >> b;
      cout << find(a, b) << endl;
   }

   return 0;
}
