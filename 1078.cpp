#include <bits/stdc++.h>

using namespace std;

int I=1;

int main()
{
    int t;
    long long n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&m);
        int mod=m%n;
        int ans=1;
        while(mod)
        {
            mod=(mod*10)+m;
            ans++;
            mod=mod%n;
        }
        printf("Case %d: %lld\n",I++,ans);
    }
    return 0;
}

