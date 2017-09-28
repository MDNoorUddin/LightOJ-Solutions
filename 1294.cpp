#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int n);
int main()
{
    int t;
    scanf("%d",&t);
    int casE=1;
    while(t--)
    {
        int a;
        scanf("%d",&a);
        if(isPalindrome(a))
            printf("Case %d: Yes\n",casE++);
        else
            printf("Case %d: No\n",casE++);
    }

    return 0;
}
bool isPalindrome(int n){
    int sum=0;
    int temp;
    int a=n;
    int i=1,digit=0;
    while(n!=0)
    {
        n/=10;
        digit++;
    }
    n=a;
    for(int j=1;j<digit;j++)
        i=i*10;
    while(n!=0)
    {
        temp=n%10;
        n/=10;
        sum+=(temp*i);
        i=i/10;
    }
    if(a==sum)
    return true;
    else return false;
}
