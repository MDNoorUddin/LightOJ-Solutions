#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 9999999
#define pfc(I,a) printf("Case %d: %d\n",I++,a)
#define pc(I) printf("Case %d:\n",I++)
#define pf(n) printf("%d\n",n)
#define sc(n) scanf("%d",&n)

int a[100001];
int tree[1000000];
int x,y,z;

int idx,val;

void buildSegmentTree(int root,int start,int end)
{
    if(start == end)
    {
        tree[root] = a[start];
        return;
    }
    int mid = (start+end)/2;

    buildSegmentTree(root*2,start,mid);

    buildSegmentTree(2*root+1,mid+1,end);

    tree[root]=tree[root*2]+tree[2*root+1];
    return;
}

int findSum(int root,int start,int end)
{
    if(start > z || end < y )return 0;
    //pf(1);

    if(start >= y && end<= z)return tree[root];
    //pf(2);
    int mid = (start + end) / 2;
    //pf(3);
    return findSum(root*2, start, mid)+findSum((2*root)+1, mid+1, end);

}

void update(int root,int start,int end)
{
    if(start == end)
    {
        //pf(12345);
        a[idx]+=val;
        tree[root]+=val;
        return;
    }
    int mid=(start+end)/2;
    if(start<=idx&&idx<=mid)update(root*2,start,mid);
    else update(root*2+1,mid+1,end);

    tree[root]=tree[2*root]+tree[2*root+1];
}

void updateZero(int root,int start,int end)
{
    //cout<<"hai\n";
    if(start == end)
    {
        //cout<<"hello ";
        pf(a[idx]);
        a[idx]=0;
        tree[root]=0;
        return;
    }
    //pf(2);
    int mid=(start+end)/2;
    if(start<=idx&&idx<=mid)updateZero(root*2,start,mid);
    else updateZero(2*root+1,mid+1,end);
    //pf(4);
    tree[root]=tree[2*root]+tree[2*root+1];
}


int main()
{
    //freopen("x.txt","w",stdout);
    int t,I=1,n,q;
    sc(t);
    while(t--)
    {
        pc(I);
        sc(n);
        sc(q);
        for(int i=1;i<=n;i++)sc(a[i]);
        buildSegmentTree(1,1,n);
        //for(int i=1;i<=20;i++)cout<<tree[i]<<" ";
        //cout<<endl;
        while(q--){
        sc(x);
        sc(y);
        if(x==1)
        {
            idx = y;
            idx++;
            updateZero(1,1,n);
        }
        else if(x==2)
        {
            sc(val);
            idx=y+1;
            update(1,1,n);
        }
        else
        {
            sc(z);
            y++;
            z++;
            pf(findSum(1,1,n));
        }
        //for(int i=1;i<=20;i++)cout<<tree[i]<<" ";
        //cout<<endl;
        }
    }
    return 0;
}
