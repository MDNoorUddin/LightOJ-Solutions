#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<math.h>
#include <utility>
#include <sstream>
#include<bitset>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef std::vector<double> vi;

#define PI acos(-1)
#define E 2.718281828459
#define G 9.81
#define pf(x,y) printf("Case %d: %d\n",x++,y)

int I=1;

int main(int argc, char** argv) {
    //freopen("c.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);

        ll g=__gcd(a,b);
        g=(a*b)/g;
        /// g=my gcd
        //cout<<l<<" "<<g<<endl;

        if(l==g)
        {
            printf("Case %d: 1\n",I++);
            continue;
        }


        if(l%g!=0)
        {
            printf("Case %d: impossible\n",I++);
            continue;
        }

        ll ans;
        set<ll> aa;
        for(ll i=1;i*i<=l;i++)
        {
            if(l%i==0)
            {
                ll first_gcd=(i*g)/__gcd(i,g);
                //cout<<"g "<<g<<endl;
                //cout<<"first "<<first_gcd<<endl;
                if(first_gcd==l&&i!=1)
                {
                    aa.insert(i);
                    break;
                }
                ll second_gcd=((l/i)*g)/__gcd((l/i),g);
                //cout<<"second "<<second_gcd<<endl;
                if(second_gcd==l)
                {
                    ans=(l/i);
                    aa.insert(l/i);
                }
            }
        }
        set<ll>::iterator it=aa.begin();
        cout<<"Case "<<I++<<": "<<*it<<endl;
    }
}
