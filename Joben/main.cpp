#include <iostream>
#include<fstream>
#include<string.h>


using namespace std;
void creareFrecventa(char s[], int fr[])
{
    int i, n;
    for(i=1;i<=26;i++)
        fr[i]=0;
    n=strlen(s);
    for(i=0;i<n;i++)
        fr[s[i]-96]++;
}
void SortDesc(int a[27])
{
    int aux,i,j;
       for(i=1;i<=26;i++)
      for(j=i;j<=26;j++)
          if(a[i]<a[j])
             {
                 aux=a[i];
                 a[i]=a[j];
                 a[j]=aux;
             }
}
int main()
{
   char sir[100006];
   int test,ok,frecventa1[27],frecventa2[27];
   unsigned int i;
   ifstream f("joben.in");
  ofstream g("joben.out");
   f>>test;
   while(test)
   {

       ok=1;
       f>>sir;
       creareFrecventa(sir,frecventa1);
       f>>sir;
       creareFrecventa(sir,frecventa2);



     SortDesc(frecventa1);
     SortDesc(frecventa2);

       for(i=1;i<=26&&ok;i++)
               if(frecventa1[i]!=frecventa2[i])
                      ok=0;

       if(ok==1)
            g<<"DA"<<'\n';
            else
              g<<"NU"<<'\n';
       test--;
   }
    return 0;
}
