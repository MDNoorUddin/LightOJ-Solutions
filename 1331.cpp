#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

#define MAX 999999999999
#define MIN -99999999999

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    int I=1;
    double r1,r2,r3;
    while(t--)
    {
        cin>>r1>>r2>>r3;
        double x=r1*r1*acos(1-((2*r2*r3)/((r1+r2)*(r1+r3))));
        double y=r2*r2*acos(1-((2*r1*r3)/((r1+r2)*(r2+r3))));
        double z=r3*r3*acos(1-((2*r1*r2)/((r1+r3)*(r2+r3))));

        x=(x+y+z)/2.00;

        r1=sqrt(r1*r2*r3*(r1+r2+r3));
        printf("Case %d: %.6lf\n",I++,r1-x);
    }
}
