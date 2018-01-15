#include <fstream>
#include <bitset>
#include <climits>
#include <cmath>
#define MAX 100000000
using namespace std;
ifstream fin("cifru.in");
ofstream fout("cifru.out");
bitset <MAX+1>p;
int v[20005],prime[1230];
int main()
{
    int cate=0,j,rx,patratP=0,c1,c2,r,n,x,max1=INT_MIN,max2=INT_MIN,i;
    p[0]=p[1]=1;
    r=10000;
    prime[++cate]=2;
    for(i=3; i<=r; i+=2)
    {
        if(!p[i])
        {
            prime[++cate]=i;
            for(j=i*i; j<=MAX; j=j+2*i)
            {
                p[j]=1;
            }
        }
    }
    /**if(r%2==0)
    {
        r++;
    }
    for(i=r; i<=MAX; i+=2)
    {
        if(p[i]==0)
        {
            prime[++cate]=i;
        }
    }**/
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        if(x>max1)
        {
            max2=max1;
            max1=x;
        }
        else if(x>max2)
        {
            max2=x;
        }
        rx=sqrt(x);
        if(rx*rx==x && x%2==0)
        {
            c1=x/2-1;
            while(p[c1]==1)
            {
                c1--;
            }
            c2=x/2+1;
            while(p[c2]==1)
            {
                c2++;
            }
            if((c1+c2==x) && (x>patratP))
            {
                patratP=x;
            }
        }
    }
    fout<<max1<<" "<<max2<<'\n'<<patratP;
    fin.close();
    fout.close();
    return 0;
}

