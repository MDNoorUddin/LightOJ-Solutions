#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<math.h>
#include <utility>
#include <sstream>
#include<bitset>

using namespace std;

typedef long long ll;
typedef std::vector<double> vi;

#define PI acos(-1)
#define E 2.718281828459
#define g 9.81
#define pf(x,y) printf("Case %d: %d\n",x++,y)

int I=1;

int main(int argc, char** argv) {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        int pre=2;
        int x;
        int count=0;
        while(n--)
        {
            cin>>x;
            //cout<<x<<" "<<pre<<endl;
            if(x==2)
            {
                pre=2;
            }
            else
            {

                int temp=x-pre;
                //cout<<temp<<" ";
                count+=temp/5;
                if(temp%5!=0)count++;
                pre=x;
                //cout<<count<<"--\n";
            }
        }
        pf(I,count);
    }
}
