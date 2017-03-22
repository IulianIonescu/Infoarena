#include <iostream>
#include<fstream>
using namespace std;

int main()
{
   ifstream f("ceas3.in");
   ofstream g("ceas3.out");
   int grad,minute,ore;
   while(f>>grad)
   {
       ore=9;
       minute=2*grad;
       while(minute>=60)
       {
           ore++;
           minute=minute-60;
       }
       if(ore>=12)
        ore-=12;
       if(ore<10)
            {
                if(minute<10)
                  g<<'0'<<ore<<':'<<'0'<<minute<<endl;
                else
                    g<<'0'<<ore<<':'<<minute<<endl;
            }
      else
                if(ore>=10)
                  {
                    if(minute<10)
                       g<<ore<<':'<<'0'<<minute<<endl;
                else
                    g<<ore<<':'<<minute<<endl;
                  }
   }
    return 0;
}
