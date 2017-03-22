#include<fstream>
#include<vector>
#include<iostream>
using namespace std;

vector <unsigned int > a[10001],b[10001];
int v[10001],suma[10001];
ifstream f("nustiu.in");
ofstream g("nustiu.out");
void dfs(int nod,int n)
{

    v[nod]=1;

     for(unsigned int i=0;i<a[nod].size();i++)
          {
              if(v[a[nod][i]]==0)
            {

                dfs(a[nod][i],n);
                if(a[a[nod][i]].size()>1)
                     {
                         suma[nod]=1+suma[nod]+suma[a[nod][i]];

                     }
                 else
                    suma[nod]=suma[nod]+1;

                 b[nod].push_back(suma[a[nod][i]]+1);
               }

          }
       if(a[nod].size()-b[nod].size()==1)
            b[nod].push_back(n-suma[nod]-1);
}

int main()
{

    unsigned int i,j,n,test,q,nimic,ok,x,y;
    f>>test;
    for(q=1;q<=test;q++)
    {
        nimic=0;
        f>>n;
        for(i=1;i<=n-1;i++)
    {
        f>>x>>y;

        a[x].push_back(y);
        a[y].push_back(x);

    }
    dfs(1,n);
     for(i=1;i<=n;i++)
    {
        ok=1;
        for(j=0;j<b[i].size()&&ok;j++)
            if(b[i][j]<=n/2)
                ok=1;
            else
                ok=0;
         if(ok==1)
                {
                    g<<i<<'\n';
                    nimic=1;
                }

    }
    if(nimic==0)
        g<<"NIMIC"<<'\n';
    for(i=1;i<=n;i++)
    {
        v[i]=0;
        suma[i]=0;
       while(a[i].size()!=0)
            a[i].pop_back();
       while(b[i].size()!=0)
          b[i].pop_back();

    }

    }



    f.close();
    g.close();
    return 0;
}

