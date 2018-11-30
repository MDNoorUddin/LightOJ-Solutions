#include <bits/stdc++.h>

using namespace std;

int MAX=1000000;

int I=1;

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int t;
    int n,q,left,right,mid,l,r,i1,i2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Case %d:\n",I++);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            /// for left boundary

            if(l>a[n-1]||r<a[0])
            {
                printf("0\n");
                continue;
            }

            if(l<=a[0])
            {
                i1=0;
            }
            else{
            left=0;
            right=n-1;
            i1=MAX;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(a[mid]<l)
                {
                    left=mid+1;continue;
                }
                if(a[mid]>=l)
                {
                    //cout<<"found "<<a[mid]<<endl;
                    i1=min(mid,i1);
                    if(a[mid]==l)
                    {
                        break;
                    }
                    right=mid-1;
                }
            }
            }

            /// right part
            i2=-1;
            if(r>a[n-1])
            {
                i2=n-1;
            }
            else{
            left=0;
            right=n-1;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(a[mid]>r)
                {
                    right=mid-1;continue;
                }
                if(a[mid]<=r)
                {
                    //cout<<"found "<<a[mid]<<endl;
                    i2=max(mid,i2);
                    if(a[mid]==r)
                    {
                        break;
                    }
                    left=mid+1;
                }
            }
            }
            if(i1==MAX)
            {
                printf("0\n");
                continue;
            }
            printf("%d\n",(i2-i1)+1);
        }

    }
    return 0;
}

