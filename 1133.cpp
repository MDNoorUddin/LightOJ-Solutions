#include<iostream>
using namespace std;
int main()
{
    int n;
    int t,o;
    char c;
    cin>>t;
    cin.ignore();
    int count=0;
    while(t-->0)
    {
        int i,j,x;
        cin>>n>>o;
        int a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin.ignore();
        for(j=0;j<o;j++)
        {
            cin>>c;
            if(c=='S')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    a[i]=a[i]+x;
            }
            if(c=='M')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    a[i]=a[i]*x;
            }
            if(c=='D')
            {
                cin>>x;
                for(int i=0;i<n;i++)
                    a[i]=a[i]/x;
            }
            if(c=='P')
            {
                int z,k;
                cin>>z>>k;
                int temp;
                temp=a[z];
                a[z]=a[k];
                a[k]=temp;
            }
            if(c=='R')
            {
                 for(int j=0,l=n-1; j<n/2; j++, l--)
                {
                    int tmp = a[j];
                    a[j] = a[l];
                    a[l] = tmp;
                }
                            }
        }
        cout<<"Case "<<++count<<":"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<a[i];
                if(i!=n-1)
                    cout<<" ";
                }
        cout<<endl;
    }
    return 0;
}
