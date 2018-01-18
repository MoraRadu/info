#include <fstream>
#include <bitset>
using namespace std;
ifstream fin("nr.in");
ofstream fout("nr.out");
int v[44]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733};
bitset<10>prim;
int main()
{
    int n,p,k,s=0,nr=0,i;
    fin>>n>>k>>p;
    prim[2]=prim[3]=prim[5]=prim[7]=1;
    for(i=1; i<=n; i++)
    {
        if(prim[v[i]%10])
        {
            s=s+v[i]%10;
        }
        if(v[i]%10==k)
        {
            nr++;
        }
    }
    fout<<s<<endl<<nr<<endl<<v[k]%10;
    fin.close();
    fout.close();
    return 0;
}
