//1492 - Follow me and be Careful

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;


struct city {
    int n;
    bool mafia;
    map<int,long double > neighbors;

    city()
    {
        n=0;
        mafia=false;
    }
};

struct path{
    vector<city> current;
    long double weight;
    path()
    {
        weight = 0;
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
        if(lhs->weight < rhs->weight)return false;
        return true;
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
        map<int,long double>::iterator it;
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
        curr->weight = 0;
        routes.push(curr);

        visited.insert(cities[s].n);

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
                curr2->weight = curr->weight/10000000 + it->second + 10000000*cities[it->first].mafia;
                routes.push(curr2);
            }
            delete curr;
        }

        cout << curr->current[0].n;
        long int mafias = curr->current[0].mafia;
        long double weight = 0.0;
        for(int i=1; i<curr->current.size(); i++){
            mafias += curr->current[i].mafia;
            weight += curr->current[i-1].neighbors[curr->current[i].n];
            cout << " " << (curr->current[i].n);
        }
        cout << endl;
        cout << mafias << " ";
        cout << setprecision(2) << fixed << weight << endl;

       /* 
        for(int i=1; i<=n; i++)
          {
          cout << "Cuidad : " << cities[i].n << endl;
          cout << "Links : " << endl;
          for(it = cities[i].neighbors.begin(); it != cities[i].neighbors.end(); it++)
          {
          cout << "\t" << it->first << ": " << it->second << endl;
          }
          }*/

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
