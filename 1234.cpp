#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

#define MAX 999999999999
#define MIN -99999999999
#define MAXSIZE 1024
#define pf(I,a) printf("Case %d: %d\n",I++,a);
#define pd(I,a) printf("Case %d: %.10lf\n",I++,a);
#define sc(a) scanf("%lld",&a)

vector<vector<int> > graph(MAXSIZE);

int nodes;

int dfs(int s,int e)
{
    vector<int> A;
    for (auto u : graph[s]) {
       if (u != e) A.push_back(dfs(u, s));
    }
    if(A.size()<nodes)return 1;
    sort(A.begin(),A.end(),greater<int>());
    int sum=1;
    for(int i=0;i<nodes;i++)
    {
        sum+=A[i];
    }
    return sum;
}

vector<double> a(100000000/1000 + 1);
void sieve()
{
    a[0]=0;
    int index=1;
    for(double i=1;i<=100000000;i+=1000,index++)
    {
        double sum=a[index-1];
        for(double j=1,k=i;j<=1000;j++,k++)sum+=double(1/k);
        a[index]=sum;
    }
    /*for(int i=0;i<=100000;i++)
    {
        cout<<i*1000<<" "<<a[i]<<endl;
    }*/
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    sieve();
    int t,u,v,I=1;
    cin>>t;
    ll n;
    while(t--)
    {
        sc(n);
        int x=n/1000;
        //cout<<x<<endl;
        double sum=a[x];
        int index=x*1000;
        x=n%1000;
        double in=index;
        for(double i=1,k=in+1;i<=x;i++,k++)
        {
            sum+=double(1.00/k);
        }
        pd(I,sum);
    }
}
