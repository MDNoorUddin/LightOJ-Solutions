#include<bits/stdc++.h>
using namespace std;
int toBinary(int n);
int main()
{
    int t;
    cin>>t;
    int casE=1;
    while(t--)
    {
        int a,b,c,d;
        scanf("%d.%d.%d.%d",&a,&b,&c,&d);
        int A,B,C,D;
        scanf("%d.%d.%d.%d",&A,&B,&C,&D);
        int m,n,o,p;
        m=toBinary(A);n=toBinary(B);o=toBinary(C);p=toBinary(D);
        if(a==m&&b==n&&c==o&&d==p)
            printf("Case %d: Yes\n",casE++);
        else
            printf("Case %d: No\n",casE++);
    }

    return 0;
}
int toBinary(int n){
    int sum=0;
    int i=0;
    int temp;
    while(n!=0)
    {
        temp=n%10;
        n/=10;
        sum+=temp*pow(2,i);
        i++;
    }
    return sum;
}
