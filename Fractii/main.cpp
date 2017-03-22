#include <iostream>
#include <fstream>
using namespace std;
 
long long v[1000001];
int main()
{
    long long i,j,n,nr=0;
    ifstream f("fractii.in");
    ofstream g("fractii.out");
    f>>n;
    for(i=1;i<=n;i++)
        v[i]=i;
    for(i=2;i<=n;i++)
    {
        if(v[i]==i)
        {
            v[i]=i-1;
            for(j=2*i;j<=n;j+=i)
                v[j]=v[j]*(i-1)/i;
        }
    }
    for(i=1;i<=n;i++)
        nr+=v[i];
    g<<2*nr-1;
 
    return 0;
}
