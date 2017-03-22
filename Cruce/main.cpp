#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream f("cruce.in");
    ofstream g("cruce.out");
    int N,M,x,y,nr_cruci=0,exista_pal_ver,exista_pal_oriz,k1,k2;
    char A[101][101];
    f>>N>>M;
    for(x=1;x<=N;x++)
        for(y=1;y<=M;y++)
           f>>A[x][y];
    for(x=2;x<N;x++)
           for(y=2;y<M;y++)
             {
                    exista_pal_ver=1;
                    exista_pal_oriz=1;
                    k1=k2=1;
                    while((exista_pal_ver==1)||(exista_pal_oriz==1))
                    {
                        if((exista_pal_ver==1)&&(x-k1>=1)&&(x+k1<=N))
                        {
                            if(A[x-k1][y]==A[x+k1][y])
                                k1++;
                            else
                                exista_pal_ver=0;
                        }
                        else
                            exista_pal_ver=0;
                        if((exista_pal_oriz==1)&&(y-k2>=1)&&(y+k2<=M))
                        {
                            if(A[x][y-k2]==A[x][y+k2])
                                k2++;
                            else
                                exista_pal_oriz=0;
                        }
                        else
                            exista_pal_oriz=0;
                    }
                    if(k1>1&&k2>1)
                        nr_cruci=nr_cruci+(k1-1)*(k2-1);

                 }
       g<<nr_cruci;

       f.close();
       g.close();
    return 0;
}
