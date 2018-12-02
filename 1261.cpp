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
    int n,m,k,x;
    char c;
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        vector<vector<int> > p(n);
        vector<vector<int> > neg(n);
        vector<bool> v(n);
        fill(v.begin(),v.end(),false);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                //Sprintf("input :");
                cin>>c>>x;
                if(c=='+')p[i].push_back(x);
                else neg[i].push_back(x);
                //cout<<c<<endl;
            }
        }

        int pp;
        scanf("%d",&pp);
        while(pp--)
        {
            scanf("%d",&x);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<p[i].size();j++)
                {
                    if(p[i][j]==x)
                    {
                        v[i]=true;
                        break;
                    }
                }
            }

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<neg[i].size();j++)
                {
                    if(neg[i][j]==x)
                    {
                        neg[i][j]=-1111;
                    }
                }
            }
        }
        bool f=true;
        for(int i=0;i<n;i++)
        {
            if(v[i])continue;
            bool vv=false;;
            for(int j=0;j<neg[i].size();j++)
            {
                if(neg[i][j]!=-1111)
                {
                    vv=true;
                    break;
                }
            }
            if(!vv)
            {
                f=false;
                break;
            }
        }
        if(f)printf("Case %d: Yes\n",I++);
        else printf("Case %d: No\n",I++);
    }
    return 0;
}
