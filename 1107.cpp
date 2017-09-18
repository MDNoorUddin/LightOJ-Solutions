#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int x1,x2,y1,y2,M,x,y;
    for(int i=1;i<=T;i++)
    {
        cin>>x1>>y1>>x2>>y2;
        cin>>M;
        cout<<"Case "<<i<<":"<<endl;
        for(int j=0;j<M;j++)
        {
            cin>>x>>y;
            if((x>=x1&&x<=x2)&&(y>=y1&&y<=y2))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
