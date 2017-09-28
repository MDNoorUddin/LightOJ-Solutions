#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int n){
    int sum=0,a=n;
    while(n)
    {
        sum=sum*10+n%10;
        n/=10;
    }if(a==sum)
    return true;
    else return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a;
        scanf("%d",&a);
        if(isPalindrome(a))
            printf("Case %d: Yes\n",i);
        else
            printf("Case %d: No\n",i);
    }

    return 0;
}

