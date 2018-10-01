#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bits/stdc++.h>

using namespace std;

#define INF 999999999999999999

typedef long long ll;

vector<ll> a(1000001);

void sieve()
{
    a[0]=1;
    for(int i=1;i<=1000000;i++)
    {
        a[i]=(i%1000003*a[i-1]%1000003)%1000003;
    }
}

ll modPow(ll x,ll n,ll m)
{
    if(n==0)return 1%m;
    ll u=modPow(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1)u=(u*x)%m;
    return u;
}

int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    int I=1;
    ll n,k;
    while(t--)
    {
        cin>>n>>k;
        ll s=a[n];
        ll b=(a[n-k]%1000003*a[k]%1000003)%1000003;
        b = modPow(b,1000003-2,1000003);
        s=((s%1000003)*(b%1000003))%1000003;
        printf("Case %d: %lld\n",I++,s);
    }
    return 0;
}
