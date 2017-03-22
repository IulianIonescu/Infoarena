#include <iostream>
#include <fstream>
#include <vector>

#define MAX 10000
using namespace std;

ifstream f("alibaba.txt");
//ofstream g("alibaba.out");

int main()
{
    int N,K,k=0,max= 0,cifra,nr=1;
    char temp;
    vector<int> number;
    vector<int>::iterator it;
    f>>N>>K;
    f>>temp;
    cifra = temp-'0';
    max = cifra;
    number.push_back(cifra);

    for(int i = 2;i<=N;++i)
        {

        f>>temp;
        cifra = temp-'0';
        if(K!=k)
        {

         if(cifra>max)
              {
             max = cifra;
             while(nr!=0)
                   {
                    number.pop_back();
                    k++;
                    nr--;
                   }
                }
             else
               {
                it = number.end();
                it--;
                while((cifra>*it)&&(K>k))
                    {
                    number.pop_back();
                    nr--;
                    it = number.end();
                    it--;
                    k++;
                    }
               }

        }

         number.push_back(cifra);
         nr++;
        }
    while(k<K)
    {
        number.pop_back();
        k++;
    }
    for(it = number.begin();it!=number.end();it++)
        cout<<*it;
    return 0;
    }
