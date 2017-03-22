#include <iostream>
#include<fstream>
using namespace std;
bool marcare[500001];
int main()
{
    int a,b,N,q,vizitez[500001],NR=0,i,j;
    ifstream f("densitate.in");
    ofstream g("densitate.out");
    f>>N>>q;

    for(i=2;i<=N;i++)
    {
        if(marcare[i]==0)
        {
            NR++;
            for(j=i+i;j<=N;j+=i)
                 marcare[j]=1;
        }
        vizitez[i]=NR;
    }
    for(i=1;i<=q;i++)
    {
        f>>a>>b;
        g<<vizitez[b]-vizitez[a-1]<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
