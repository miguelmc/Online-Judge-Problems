#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;
#define edge pair<int,int>
#define MAX 101

vector< pair< double, edge > > g;
pair<double,double> points[MAX];
double total;
int E;
double parent[MAX];

int findset(int x, double *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    total = 0.0;
    sort(g.begin(), g.end());
    for(i = 0; i<E ; i++)
    {
        pu = findset(g[i].second.first, parent);
        pv = findset(g[i].second.second, parent);
        if(pu != pv)
        {
            total += g[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }
}

int main()
{
    int n;
    double x, y, distance;
    cin >> n;
    for(int i=0; i<n; i++)
        parent[i] = i;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        points[i] = make_pair(x,y);
    }

    E = (n*(n-1))/2;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            distance = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
            g.push_back(pair<double, edge>(distance, edge(i,j)));
            g.push_back(pair<double, edge>(distance, edge(j,i)));
        }
    }

    kruskal();

    cout << setprecision(2) << fixed << total << endl;
    return 0;
}
