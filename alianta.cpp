#include <fstream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
ifstream fin("alianta.in");
ofstream fout("alianta.out");
int x[1005],y[1005],z[1005],d[1000005],v[1005];
int main()
{
    int n,ap,minim=INT_MAX,maxim=INT_MIN,jmax,i,j,c1,c2,c=0;
    fin>>n;
    for(i=1; i<=n ;i++)
    {
        fin>>x[i]>>y[i]>>z[i];
    }
    for(i=1; i<=n ;i++)
    {
        for(j=i+1; j<=n; j++)
        {
            c1=x[i]-x[j];
            c2=y[i]-y[j];
            jmax=c1*c1+c2*c2;
            if(jmax>d[i])
            {
                d[i]=jmax;
            }
            if(jmax>d[j])
            {
                d[j]=jmax;
            }
        }
        if(d[i]<minim)
        {
            minim=d[i];
            c=0;
        }
        if(d[i]==minim)
        {
            c++;
            v[c]=z[i];
        }
    }
    sort(v+1, v+c+1);
    fout<<minim<<endl<<c<<endl;
    for(i=1; i<=c; i++)
    {
        fout<<v[i]<<" ";
    }
    fin.close();
    fout.close();
    return 0;
}
