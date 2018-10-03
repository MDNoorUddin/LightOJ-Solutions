#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<bitset>
#include<string>
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
    //cout<<a[4000]<<endl;
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
    //freopen("c.txt","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int I=1;
    ll u,v,w;
    while(t--)
    {
        int n;
        cin>>n;
        vector< vector<pair<ll,ll> > > a(n);
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        vector<ll> distance(n);
        fill(distance.begin(),distance.end(),INF);
        distance[0]=0;
        priority_queue<pair<ll,ll> > visit;
        visit.push({0,0});
        vector<bool> processed(n);
        fill(processed.begin(),processed.end(),false);
        while(!visit.empty())
        {
            ll tp=visit.top().second;
            visit.pop();
            if(processed[tp]==1)continue;
            processed[tp]=1;
            for(int i=0;i<a[tp].size();i++)
            {
                    v=a[tp][i].first;
                    w=a[tp][i].second;
                    if(distance[v]>distance[tp]+w)
                    {
                        distance[v] = distance[tp]+w;
                        visit.push({-distance[v],v});
                    }
            }
        }
        ll mx=0,index=-1;;
        for(int i=0;i<n;i++)
        {
            if(distance[i]>mx){
                mx=distance[i];
                index=i;
            }
            //cout<<distance[i]<<" ";
        }
        //cout<<"\nfarest node:"<<index<<endl;
        //cout<<endl;
        ll U=index;

        fill(distance.begin(),distance.end(),INF);
        distance[index]=0;
        visit.push({0,index});
        fill(processed.begin(),processed.end(),false);
        while(!visit.empty())
        {
            ll tp=visit.top().second;
            visit.pop();
            if(processed[tp]==1)continue;
            processed[tp]=1;
            for(int i=0;i<a[tp].size();i++)
            {
                    v=a[tp][i].first;
                    w=a[tp][i].second;
                    if(distance[v]>distance[tp]+w)
                    {
                        distance[v] = distance[tp]+w;
                        visit.push({-distance[v],v});
                    }
            }
        }
        mx=0;index=-1;;
        for(int i=0;i<n;i++)
        {
            if(distance[i]>mx){
                mx=distance[i];
                index=i;
            }
            //cout<<distance[i]<<" ";
        }
        cout<<"Case "<<I++<<": "<<mx<<endl;
    }
    return 0;
}
