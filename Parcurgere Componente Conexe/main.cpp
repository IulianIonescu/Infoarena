#include<fstream>
#include<vector>
#include<iostream>
using namespace std;
 
vector < int > a[100001];
int v[100001];
void dfs(int nod)
{
    v[nod]=1;
 
     for( int i=0;i<a[nod].size();i++)
          if(v[a[nod][i]]==0)
            {
                dfs(a[nod][i]);
            }
 
}
int main()
{
    int i,n,m,x,y,nr=0;
    ifstream f("dfs.in");
    ofstream g("dfs.out");
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
 
        a[x].push_back(y);
        a[y].push_back(x);
 
    }
    for(i=1;i<=n;i++)
        if(v[i]==0)
            {
                nr++;
 
                dfs(i);
 
            }
    g<<nr;
    f.close();
    g.close();
    return 0;
}
