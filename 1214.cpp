

    #include<bits/stdc++.h>

    using namespace std;

    typedef long long ll;

    bitset<10000001> prime;

    map<int,int> mp;
    vector<int> List;

    void sieve()
    {
        prime[1]=1;
       for(int i=2;i*i<=10000001;i++)
       {
           if(prime[i]==1)continue;
           for(int j=i*2;j<=10000001;j+=i)
           {
               prime[j]=1;
           }
       }
       for(int i=2;i<=10000001;i++)
       {
           if(prime[i]==0)List.push_back(i);
       }
       return;
    }

    ll modPow(ll x,ll n,ll m)
    {
        if(n==0)return 1%m;
        ll u=modPow(x,n/2,m);
        u=(u*u)%m;
        if(n%2==1)u=(u*x)%m;
        return u;
    }

    bool isPrime(ll n)
    {
        if(n==1)return false;
        if(n==2)return true;
        if(n%2==0)return false;
        for(ll i=3;i<=sqrt(n);i++)
        {
            if(n%i==0)return false;
        }
        return true;
    }

    int main()
    {
        //freopen("c.txt","w",stdout);
        int t,I=1;
        cin>>t;
        while(t--)
        {
            string str;
            ll n;
            cin>>str;
            cin>>n;
            ll mod=0;
            int i=0;
            if(str[0]=='-')i++;
            for(;i<str.length();i++)
            {
               int x=str[i]-48;
               mod=(mod*10)+x;
               mod=mod%n;
            }
            if(mod==0)
            {
                printf("Case %d: divisible\n",I++);
            }
            else
            {
                printf("Case %d: not divisible\n",I++);
            }
        }
        return 0;
    }
