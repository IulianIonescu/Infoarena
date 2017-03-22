#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int v[1000012];
int cautare(int caut,int st,int dr)
{
    int mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==caut)
            return mij;
        if(caut<v[mij])
           dr=mij-1;
        else
           st=mij+1;
    }
    return -1;
}
int main()
{
    int i,j,z,n,gasit,k=0,ok=1;
    long numere[101],s;
    ifstream f("loto.in");
    ofstream g("loto.out");
    f>>n>>s;
   for(i=1;i<=n;i++)
        f>>numere[i];

    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
            for(z=j;z<=n;z++)
                v[++k]=numere[i]+numere[j]+numere[z];

    sort(v+1,v+k+1);

    for(i=1;i<=k&&ok;i++)
        if(cautare(s-v[i],1,k)!= -1)
        {
            gasit= v[i];
            ok=0;
        }
        ok=1;
    if(!gasit)
        g<<-1;
    else
    {
        for(i=1;i<=n&&ok;i++)
            for(j=i;j<=n&&ok;j++)
                for(z=j;z<=n&&ok;z++)
                    if(gasit==numere[i]+numere[j]+numere[z])
                    {
                        g<<numere[i]<<" "<< numere[j]<<" "<<numere[z]<<" ";
                        ok=0;
                    }
           ok=1;
        for(i=1;i<=n&&ok;i++)
            for(j=i;j<=n&&ok;j++)
                for(z=j;z<=n&&ok;z++)
                    if(s-gasit==numere[i]+numere[j]+numere[z])
                    {
                        g<<numere[i]<<" "<<numere[j]<<" "<<numere[z]<<" ";
                        ok=0;
                    }
    }
    return 0;
}
