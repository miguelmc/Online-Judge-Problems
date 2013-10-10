/*
 * 2299 - Elevator Trouble
 * ACCEPTED
 */

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int f, s, g, u, d, c;
    set<int> visited;
    visited.insert(s);
    c = 0;
    cin >> f >> s >> g >> u >> d;
    if(s == g)
    {
        cout << 0 << endl;
    }
    else if((g > s && u == 0) || (g < s && d == 0))
    {
        cout << "use the stairs" << endl;
    }
    else
    {
        if(g > s)
        {
            c = (g-s)/u;
            if((g-s)%u != 0 && u==d)
            {
                cout << "use the stairs" << endl;
                return 0;
            }
            s += u*c;
            visited.insert(s);
            while(s != g)
            {
                if(g > s)
                {
                    s += u;
                    if(visited.find(s) != visited.end())
                    {
                        cout << "use the stairs" << endl;
                        return 0;
                    }
                    else
                        visited.insert(s);
                    if(s>f)
                    {
                        s-=u;
                        --c;
                        while(s+u > f)
                        {
                            s-=d;
                            if(visited.find(s) != visited.end())
                            {
                                cout << "use the stairs" << endl;
                                return 0;
                            }
                            else
                                visited.insert(s);
                            ++c;
                        }
                    }
                }
                else
                {
                    s -= d;
                    if(visited.find(s) != visited.end())
                    {
                        cout << "use the stairs" << endl;
                        return 0;
                    }
                    else
                        visited.insert(s);
                    if(s<0)
                    {
                        s+=d;
                        --c;
                        while(s-d < 0)
                        {
                            s+=u;
                            if(visited.find(s) != visited.end())
                            {
                                cout << "use the stairs" << endl;
                                return 0;
                            }
                            else
                                visited.insert(s);
                            ++c;
                        }
                    }
                }
                ++c;
            }
        }
        else
        {
            c = (s-g)/d;
            if((s-g)%d != 0 && u==d)
            {
                cout << "use the stairs" << endl;
                return 0;
            }
            s -= d*c;
            visited.insert(s);
            while(s != g)
            {
                if(g > s)
                {
                    s += u;
                    if(visited.find(s) != visited.end())
                    {
                        cout << "use the stairs" << endl;
                        return 0;
                    }
                    else
                        visited.insert(s);
                    if(s>f)
                    {
                        s-=u;
                        --c;
                        while(s+u > f)
                        {
                            s-=d;
                            if(visited.find(s) != visited.end())
                            {
                                cout << "use the stairs" << endl;
                                return 0;
                            }
                            else
                                visited.insert(s);
                            ++c;
                        }
                    }
                }
                else
                {
                    s -= d;
                    if(visited.find(s) != visited.end())
                    {
                        cout << "use the stairs" << endl;
                        return 0;
                    }
                    else
                        visited.insert(s);
                    if(s<0)
                    {
                        s+=d;
                        --c;
                        while(s-d < 0)
                        {
                            s+=u;
                            if(visited.find(s) != visited.end())
                            {
                                cout << "use the stairs" << endl;
                                return 0;
                            }
                            else
                                visited.insert(s);
                            ++c;
                        }
                    }
                }
                ++c;
            }

        }

        cout << c << endl;
    }
    return 0;
}
