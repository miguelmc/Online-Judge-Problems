//1492 - Follow me and be Careful

#include <iostream>
#include <queue>
#include <set>
#include <iomanip>
using namespace std;


struct city {
    int n;
    bool mafia;
    set<pair<int,long double> > neighbors;

    city()
    {
        n=0;
        mafia=false;
    }
};

struct path{
    vector<city> current;
    int mafias;
    long double weight;
    path()
    {
        mafias = 0;
        weight=0;
    }
    path(vector<city> c)
    {
        for(int i=0; i<c.size(); i++)
            current.push_back(c[i]);
    }
};

struct mycomparison
{
    bool operator() (const path* lhs, const path* rhs) const
    {
        if(lhs->mafias < rhs->mafias)return false;
        else if(lhs->mafias > rhs->mafias)return true;
        else
        {
            if(lhs->weight < rhs->weight)
                return false;
            return true;
        }
        return false;
    }
};
int main()
{
    int n, e, s, t, x, y, c, mafia;
    long double d;
    path *curr;
    while(cin >> n){
        cin >> e >> s >> t;
        priority_queue<path*, vector<path*>,mycomparison> routes;
        set<int>visited;
        set<pair<int,long double> >::iterator it;
        city cities[n+1];
        for(int i=1; i<=n; i++)
            cities[i].n=i;

        for(int i=0; i<e; i++)
        {
            cin >> x >> y >> d;
            cities[x].neighbors.insert(make_pair(y, d));
            cities[y].neighbors.insert(make_pair(x, d));
        }

        cin >> c;
        for(int i=0; i<c; i++)
        {
            cin >> mafia;
            cities[mafia].mafia = true;
        }

        curr = new path();
        curr->current.push_back(cities[s]);
        curr->mafias = 0;
        curr->weight = 0;
        routes.push(curr);

        visited.insert(cities[s].n);

        /*for(int i=1; i<=n; i++)
          {
          cout << "Cuidad : " << cities[i].n << endl;
          cout << "Links : " << endl;
          for(it = cities[i].neighbors.begin(); it != cities[i].neighbors.end(); it++)
          {
          cout << "\t" << it->first << ": " << it->second << endl;
          }
          }
          */
        while(!routes.empty())
        {
            curr = routes.top();
            routes.pop();
            if(curr->current.back().n == t)
                break;
            for(it=curr->current.back().neighbors.begin(); it != curr->current.back().neighbors.end(); it++)
            {
                path *curr2 = new path(curr->current);
                curr2->current.push_back(cities[it->first]);
                if(visited.find(curr2->current.back().n) != visited.end())
                    continue;
                else
                    visited.insert(curr2->current.back().n);
                curr2->weight = curr->weight + it->second;
                curr2->mafias = curr->mafias + (cities[it->first].mafia ? 1 : 0);
                routes.push(curr2);
            }
            delete curr;
        }

        cout << curr->current[0].n;
        for(int i=1; i<curr->current.size(); i++)
            cout << " " << (curr->current[i].n);
        cout << endl;
        cout << curr->mafias << " ";
        cout << setprecision(2) << fixed << curr->weight << endl;

        while(!routes.empty()){
            delete routes.top();
            routes.pop();
        }
        visited.clear();
    }
    /*
       while(!routes.empty())
       {
       curr = routes.top();
       routes.pop();
       cout << "weight: " << curr->weight << endl;
       cout << "mafias " << curr->mafias << endl;
       for(int i=0; i<curr->current.size(); i++)
       cout << (curr->current[i].n) << " ";
       cout << endl << endl;
       }*/

}
