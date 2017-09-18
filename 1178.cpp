#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int c=1;
    for(int i=1;i<=t;i++)
    {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double s=(d+b+(a-c))/2.00;
        s=sqrt(s*(s-b)*(s-d)*(s-(a-c)));
        double height=(s*2.00)/(a-c);
        double area=.5*height*(a+c);
        printf("Case %d: %.6lf\n",i,abs(area));
    }
}
