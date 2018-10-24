// C++ program to find LCM of First N Natural Numbers.
#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

typedef long long ll;;

// array to store all prime less than and equal to 10^6
#define sz 100000100
const int real_size = 5761509;

unsigned primes[real_size],cnt;
unsigned dp[real_size];

// utility function for sieve of sieve of Eratosthenes
int N =100000100;
int status[100000000/32+10];
bool Check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){	return N=N | (1<<pos);}

void sieve()
{
    int  i, j, sqrtN;
     sqrtN = ll( sqrt( N ) );
     for( i = 3; i <= sqrtN; i += 2 )
     {
         //cout<<1<<endl;
		 if( Check(status[i/32],i%32)==0)
		 {
	 		 for( j = i*i; j < sz; j += 2*i )
			 {
				 status[j/32]=Set(status[j/32],j % 32)   ;
	 		 }
		 }
	 }
	 //puts("2");
	 primes[cnt++]=2;
	 for(int i=3;i<sz;i+=2)
        if( Check(status[i/32],i%32)==0)
			primes[cnt++]=i;
    //for(int i=0;i<250;i++)cout<<primes[i]<<endl;
}

unsigned find_sqrt_ans(int x)
{
    int k = sqrt(x), now;
    unsigned ret=1, cnts;
    for (int i = 0; primes[i]<=k; i++)
    {
        now = x/primes[i];
        cnts=1;
        while(now>=primes[i])
        {
            now/=primes[i];
            cnts*=primes[i];
        }
        ret*=cnts;
    }
    return ret;
}
int main()
{
    //freopen("c.txt","w",stdout);
    //cout<<"hello\n";
	sieve();
	//cout<<"hello\n";
	dp[0]=2;
    for (int i = 1; i<cnt; i++)
        dp[i]=(dp[i-1]*primes[i]);
	int t,I=1;
	scanf("%d",&t);
	int N;
	while(t--){
    scanf("%d",&N);
	//cout << LCM(N);
	unsigned xans=find_sqrt_ans(N);
    xans*=dp[upper_bound(primes,primes+cnt,N)-primes-1];
	printf("Case %d: %u\n",I++,xans);
	};
	return 0;
}
