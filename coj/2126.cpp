#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;

struct path{
    int jumps;
    int A, B;
};

struct cmp{
    bool operator()(const path *p1, const path *p2)const
    {
        return p1->jumps > p2->jumps;
    }
};

int main()
{
    int n, fi, q, *fis, a, b;
    set<pair<int,int> > visited;
    map<pair<int,int>,int > already;
    while(cin >> n)
    {
        fis = new int[n+1];
        priority_queue<path*, vector<path*>, cmp> paths;
        for(int i=1;  i<=n; i++)
        {
            cin >> fis[i];
        }
        cin >> q;
        for(int i=0; i<q; i++)
        {
            cin >> a >> b;
            if(already.find(make_pair(a,b)) != already.end())
            {
                cout << already[make_pair(a,b)] << endl;
                continue;
            }
            path *temp = new path;
            temp->jumps = 0;
            temp->A = a;
            temp->B = b;
            paths.push(temp);
            while(!paths.empty())
            {
                temp = paths.top();
                //cout << temp->jumps << " " << temp->A << " " << temp->B << endl;
                paths.pop();
                if(temp->A == temp->B)
                {
                    paths.push(new path);
                    break;
                }

                if(visited.find(make_pair(temp->A,temp->B)) == visited.end())
                {
                    visited.insert(make_pair(temp->A,temp->B));

                    path *newOne = new path;
                    newOne->jumps = temp->jumps+1;
                    newOne->A = fis[temp->A];
                    newOne->B = temp->B;
                    paths.push(newOne);

                    newOne = new path;
                    newOne->jumps = temp->jumps+1;
                    newOne->A = temp->A;
                    newOne->B = fis[temp->B];
                    paths.push(newOne);
                    delete temp;
                }
            }

            if(paths.empty()){
                cout << -1 << endl;
                already[make_pair(a,b)] = -1;
                already[make_pair(b,a)] = -1;
            }
            else{
                cout << temp->jumps << endl;
                already[make_pair(a,b)] = temp->jumps;
                already[make_pair(b,a)] = temp->jumps;
            }

            while(!paths.empty())
            {
                delete paths.top();
                paths.pop();
            }
            visited.clear();
            already.clear();
            delete temp;
        }
    }

    return 0;
}
