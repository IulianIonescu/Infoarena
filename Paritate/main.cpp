#include <iostream>
#include<math.h>
#include<fstream>
using namespace std;
 char vectorOctet[60001];
 int vectorSecvIncorecte[60001];
int determinareSecvente(int &lung,int &k)
{
    ifstream f("paritate.in");
    char MSB,caracter;
    int secventa=-1,i,nr1,numar,ok=1;
    while(f>>MSB)
    {
        secventa++;
        nr1=0;
        numar=0;
        for(i=1;i<=7;i++)
        {
            f>>caracter;
            if(caracter=='1')
            {
                nr1++;
                numar=numar+pow(2,7-i);

            }
        }
        if(numar==10)
            vectorOctet[++lung]='\n';
        else
            vectorOctet[++lung]=numar;
        if(nr1%2!=MSB-48)
        {
            ok=0;
            vectorSecvIncorecte[++k]=secventa;
        }
    }
    return ok;
}
int main()
{
   int i,lung=-1,k=-1;
   ofstream g("paritate.out");
  if(determinareSecvente(lung,k)==1)
    {
        g<<"DA"<<'\n';
        for(i=0;i<=lung;i++)
      g<<vectorOctet[i];
    }
  else
    {
        g<<"NU"<<'\n';
        for(i=0;i<=k;i++)
      g<<vectorSecvIncorecte[i]<<" ";
    }
    return 0;
}
