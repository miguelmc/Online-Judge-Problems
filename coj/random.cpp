#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ofstream out;
    out.open("testCases.txt");
    srand (time(NULL));

    out << 1 << endl;
    for(int i=0;i<1000000; i++)
    {
        out << rand();
    }
    out << endl;
    out.close();

    return 0;
}
