#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int casE=1;
    unsigned long long int cake;
    while(t--)
    {
        cin>>cake;
        if(cake%2!=0)
        {
            printf("Case %d: Impossible\n",casE++);
        }
        else
        {
            long long odd,even;
            long long divide;
            for(long long i=2;i<=cake/2;i+=2)
            {
                divide=cake/i;
                if(cake%i==0)
                {
                    if(divide%2!=0){
                    odd=divide;
                    even=i;
                    break;
                    }
                }
            }
            printf("Case %d: %lld %lld\n",casE++,odd,even);

        }
    }
}
