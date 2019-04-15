#include<bits/stdc++.h>

using namespace std;

int I=1;
typedef long long ll;

vector<ll> tree(400001);
vector<ll> lazy(400001);
vector<ll> a(100001);



void createSegmentTree(int k,int l,int h)
{
    if(l==h)
    {
        tree[k]=a[l];
        lazy[k]=0;
        return;
    }
    int mid=(l+h)/2;
    createSegmentTree(2*k,l,mid);
    createSegmentTree(2*k+1,mid+1,h);
    tree[k]=tree[2*k]+tree[2*k+1];
}

void update(ll k,ll start,ll end,ll l,ll r,ll val)
{
        if(start>r||end<l)return;

    if(lazy[k])
    {
        tree[k]+=(end-start+1)*lazy[k];
        if(start!=end)
        {
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=0;
    }
    if(start>=l&&end<=r)
    {
        tree[k]+=val;
        if(start!=end)
        {
            lazy[2*k]+=val;
            lazy[2*k+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update(2*k,start,mid,l,r,val);
    update(2*k+1,mid+1,end,l,r,val);
    //tree[k]=tree[k*2]+tree[(k*2)+1];

}
ll query(ll k,ll start,ll end,ll l,ll r)
{
                if(start>r||end<l)return 0;


    if(lazy[k])
    {
        tree[k]+=(end-start+1)*lazy[k];
        if(start!=end)
        {
            lazy[2*k]+=lazy[k];
            lazy[2*k+1]+=lazy[k];
        }
        lazy[k]=0;
    }

    if(start>=l&&end<=r)
    {
        return tree[k];
    }
    int mid=(start+end)/2;
    return query(2*k,start,mid,l,r)+query(2*k+1,mid+1,end,l,r);


}
int main()
{
    //freopen("c.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int I=1;
    char str[100001];
    while(t--)
    {
        printf("Case %d:\n",I++);

        scanf("%s",str);
        int n,k;
        n=strlen(str);
        scanf("%d",&k);
        fill(tree.begin(),tree.end(),0);
        //
        fill(lazy.begin(),lazy.end(),0);
        for(int i=0;i<n;i++)
        {
            a[i]=str[i]-48;
        }
        createSegmentTree(1,0,n-1);
        char c[2];
        int i,j;
        while(k--)
        {

            scanf("%s%d",c,&i);
            //scanf("%c %d",&c,&i);
            if(c[0]=='Q')
            {
                printf("%d\n",query(1,0,n-1,i-1,i-1)%2);
                /*for(int i=1;i<=n;i++)
                {
                    cout<<a[i]<<" ";
                }
                cout<<endl;*/
            }
            else
            {
                scanf("%d",&j);
                update(1,0,n-1,i-1,j-1,1);
            }
        }
    }
}
