
#include<iostream>
#include<vector>
#include<string>
#include<string.h>
#include<math.h>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<stack>
#include<deque>
#include<stdio.h>

using namespace std;

#define ll long long
#define INF 9999999
#define pfc(I,a) printf("Case %d: %d\n",I++,a)
#define pc(I) printf("Case %d:\n",I++)
#define pf(n) printf("%d\n",n)
#define sf(n) scanf("%d",&n)

vector<int> tree(10000001);
vector<int> a(100001);

int l,r;

void createSegmentTree(int root,int start,int End)
{
    if(start == End)
    {
        tree[root] = a[start];
        return;
    }
    int mid = (start + End) / 2;

    createSegmentTree(2*root, start, mid);
    createSegmentTree(2*root+1, mid+1, End);

    tree[root] = min(tree[2*root],  tree[2*root + 1]);

    return;
}

int Query(int root,int start,int End)
{
    if(start>r || End<l)return INF;
    if(start>=l&&End<=r)
    {
        return tree[root];
    }
    int mid=(start+End)/2;
    return min(Query(root*2,start,mid),Query(root*2+1,mid+1,End));
}

int main()
{
    int t;
    sf(t);
    int n,I=1;
    int query;
    while(t--){
        pc(I);
        sf(n);
        sf(query);
        for(int i=1;i<=n;i++)sf(a[i]);
        createSegmentTree(1,1,n);
        while(query--)
        {
            sf(l);
            sf(r);
            pf(Query(1,1,n));
        }
    }
    return 0;
}

