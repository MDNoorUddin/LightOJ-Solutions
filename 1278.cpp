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
#include<bitset>
using namespace std;

typedef long long ll;

#define MAX 999999999999
#define MIN -99999999999

vector<ll> prime;
bitset<10000000> x;
void sieve()
{
    for(ll i=3;i*i<=10000000;i+=2)
    {
        if(x[i]==1)continue;
        for(int j=i*i;j<10000000;j+=2*i)x[j]=1;
    }
    prime.push_back(2);
    for(ll i=3;i<10000000;i+=2)
    {
        if(x[i]==0)prime.push_back(i);
    }
}

int factorization(ll n)
{
    //vector<int> mul;
    int ans=1;
    for(int i=0;i<prime.size();i++)
    {
        int temp=0;
        if(n<prime[i])break;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            temp++;
        }
        if(i!=0)
        {
            ans=ans*(temp+1);
        }
    }
    if(n!=1)
    {
        ans *= 2;
    }
    return ans-1;
}
int main()
{
    sieve();
    int t,I=1;
    scanf("%d",&t);
    ll n;
    while(t--)
    {
        scanf("%lld",&n);
        printf("Case %d: %d\n",I++,factorization(n));
    }
}
