#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    for(int I=1;I<=n;I++)
    {
        char x[200],y[200];
        string X,Y;
        gets(x);
        gets(y);
        for(int i=0;i<strlen(x);i++)
        {
            if(x[i]>=65&&x[i]<=90)
                x[i]=x[i]+32;
            if(x[i]!=' ')
                X=X+x[i];
        }
        for(int i=0;i<strlen(y);i++)
        {
            if(y[i]>=65&&y[i]<=90)
                y[i]=y[i]+32;
            if(y[i]!=' ')
                Y=Y+y[i];
        }
        sort(X.begin(),X.end());
        sort(Y.begin(),Y.end());
        if(X==Y)
            cout<<"Case "<<I<<": Yes\n";
        else
            cout<<"Case "<<I<<": No\n";
            //cout<<X<<endl;
            //cout<<Y<<endl;
    }
}
