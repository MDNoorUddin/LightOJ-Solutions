#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int i=1;
    while(t--)
    {
        int ax,ay,bx,by,cx,cy,dx,dy;
        scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
        dx=ax+cx-bx;
        dy=ay+cy-by;
        int area=((ax*by)+(bx*cy)+(cx*dy)+(dx*ay))-((ay*bx)+(by*cx)+(cy*dx)+(dy*ax));
        area=0.5*area;
        printf("Case %d: %d %d %d\n",i++,dx,dy,abs(area));
    }
    return 0;
}
