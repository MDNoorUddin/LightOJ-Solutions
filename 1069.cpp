#include<iostream>
using namespace std;
int main()
{
    int t;

    cin >> t;

    for(int I=1;I<=t;I++)
    {
        int a,b,sum=0;

        cin >> a >> b;
        if(b>=a)
        {
            for(int i=b;i>0;i--)
            {
                sum=sum+4;
            }
            sum+=10;
            sum+=9;
        }
        else
        {
            for(int J=b;J<a;J++,b++)
                sum=sum+4;
            for(int i=b;i>0;i--)
            {
                sum=sum+4;
            }
            sum+=19;
        }
        cout<<"Case "<<I<<": "<<sum<<endl;
    }
    return 0;
}
