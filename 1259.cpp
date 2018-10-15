
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
        sieve();
        int t;
        scanf("%d",&t);
        int n,i,j,c,I=1,x;
        while(t--)
        {
            scanf("%d",&n);
            if(n==4)
            {
                printf("Case %d: 1\n",I++);continue;
            }
            int i=2;
            int index=0;
            int c=0;
            while(true)
            {
                if(List[index]>(n/2))break;
                if(prime[n-List[index]]==0){
                    c++;
                    //cout<<n-List[index]<<" "<<List[index]<<endl;
                }
                index++;
            }
            printf("Case %d: %d\n",I++,c);
        }
        return 0;
    }
