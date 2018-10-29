#include<bits/stdc++.h>

using namespace std;

#define  ll long long
#define sc(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define  pc(I) printf("Case %d:\n",I++)
#define pf(n) printf("%lld\n",n)

vector<ll> tree(1000000);
vector<ll> lazy(1000000);
vector<ll> a(100001);
int l,r;
ll val;

void build(int node,int start,int end)
{
    if(start==end)// leaf node
    {
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;//non leaf node
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node]=tree[node*2]+tree[node*2+1];
    return;
}

void updateRange(int node,int start,int end)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(end-start+1)*lazy[node];
        if(start!=end)//non-leaf node so they have childs
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start>=l&&end<=r)
    {
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    updateRange(node*2, start, mid);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll queryRange(int node, int start, int end)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = queryRange(node*2, start, mid);         // Query left child
    ll p2 = queryRange(node*2 + 1, mid + 1, end); // Query right child
    return (p1 + p2);
}

int main()
{
    //freopen("c.txt","w",stdout);
    int t;
    sc(t);
    int n,q,I=1,x,y,v,mod;
    while(t--)
    {
        fill(tree.begin(),tree.end(),0);
        fill(lazy.begin(),lazy.end(),0);
        fill(a.begin(),a.end(),0);
        pc(I);
        sc(n);
        sc(q);
        //for(int i=1;i<=n;i++)sc(a[i]);
        build(1,1,n);
        while(q--){
        sc(mod);
        sc(l);
        sc(r);
        l++;
        r++;
        if(mod==0)
        {
            sc(val);
            updateRange(1,1,n);
        }
        else
        {
            pf(queryRange(1,1,n));
        }
        //for(int i=1;i<=20;i++)cout<<tree[i]<<" ";
        //cout<<endl;
        }
    }
}
