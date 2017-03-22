#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main()
{
  char sir[131073];
  unsigned int lung,mai_caut,pas,z,ok,test,i,q;
ifstream f("prefixe.in");
ofstream g("prefixe.out");
f>>test;
for(q=1;q<=test;q++)
{
    char prelucrez[131073]={0};
    f>>sir;
    if(strlen(sir)==1)
       g<<0<<'\n';
    else
        g<<0<<' ';

    prelucrez[0]=sir[0];


    for(i=1;i<strlen(sir);i++)
    {
        prelucrez[i]=sir[i];
       lung=1; mai_caut=1;
       for(pas=0;pas<strlen(prelucrez)-1&&mai_caut;pas++)
       {
           ok=1;
           for(z=0;z<strlen(prelucrez)-lung&&ok;z++)
           {
               if(prelucrez[z]!=prelucrez[z+lung])
                  ok=0;

           }
           lung++;
           if(ok==1)
                mai_caut=0;
       }
       if(ok==1)
          g<<strlen(prelucrez)-lung+1<<' ';
       else
         g<<0<<' ';

    }

   g<<'\n';
}

f.close();
g.close();
    return 0;
}
