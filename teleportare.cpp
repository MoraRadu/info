#include <fstream>
#include <bitset>
#include <cmath>
using namespace std;
ifstream fin("teleportare.in");
ofstream fout("teleportare.out");
bitset<1000000>p;
short ap[10000];
int main()
{
    int r,cateP,x,d,v,n,m,i,pas,j,P,maxim;
    fin>>v;
    fin>>n>>m;
    r=sqrt(n);
    p[0]=p[1]=1;
    cateP=1;
    for(i=3; i<=r; i+=2)
    {
        if(p[i]==0)
        {
            pas=2*i;
            cateP++;
            for(j=i*i; j<=n; j+=pas)
            {
                p[j]=1;
            }
        }
    }
    r+=(r%2==0);
    for(i=r; i<=n; i+=2)
    {
        if(p[i]==0)
        {
            cateP++;
        }
    }
    for(i=1; i<=m; i++)
    {
        fin>>x;
        d=2;
        while(x>1)
        {
            P=0;
            while(x%d==0)
            {
                P++;
                x=x/d;
            }
            if(P>0)
            {
                ap[d]++;
            }

            if(d*d<=x)
            {
                d++;
            }
            else
            {
                d=x;
            }
        }
    }
    if(v==1)
    {
        if(ap[2]!=0)
        {
            cateP--;
        }
        for(i=3; i<=min(n,10000); i+=2)
        {
            if(ap[i]!=0)
            {
                cateP--;
            }
        }
        fout<<cateP;
    }
    else
    {
        maxim=ap[2];
        for(i=1; i<=min(n,10000); i+=2)
        {
            if(ap[i]>maxim)
            {
                maxim=ap[i];
            }
        }
       if(ap[2]==maxim)
       {
           fout<<2<<" ";
       }
       for(i=1; i<=min(n,10000); i+=2)
       {
           if(ap[i]==maxim)
           {
               fout<<i<<" ";
           }
       }
    }
    fin.close();
    fout.close();
    return 0;
}
