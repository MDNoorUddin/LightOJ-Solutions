#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t,I=1;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        ll sum=0;
        map<int,int> mp;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x==0)
            {
                sum+=x+1;
                continue;
            }
            //cout<<mp[x]<<" ";
            if(!mp[x]){
                sum+=(x+1);
                mp[x]++;
            }
            else
            {
                mp[x]++;
                if(mp[x]==x+1)
                {
                    mp[x]=0;
                }
            }
            //cout<<sum<<endl;
        }
        cout<<"Case "<<I++<<": "<<sum<<'\n';
    }
    return 0;
}

