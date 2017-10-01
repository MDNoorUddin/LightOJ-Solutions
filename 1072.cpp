#include<bits/stdc++.h>
using namespace std;
#define PI 3.14159265
int main()
{
    int t;
    cin>>t;
    int Case=1;
    while(t--)
    {
        double R,n,r;
        cin>>R>>n;
        n=360/n;
        double param=n/2;
        n=sin (param*PI/180);
        R=n*R;
        r=R/(n+1);
        printf("Case %d: %lf\n",Case++,r);
    }
}
