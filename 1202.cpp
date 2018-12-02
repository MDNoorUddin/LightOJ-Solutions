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
    int t,x1,y1,x2,y2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        char first,second;
        if(x1%2==0)
        {
            if(y1%2!=0)first='b';
            else first='w';
        }
        else
        {
            if(y1%2!=0)first='w';
            else first='b';
        }

        if(x2%2==0)
        {
            if(y2%2!=0)second='b';
            else second='w';
        }
        else
        {
            if(y2%2!=0)second='w';
            else second='b';
        }

        if(first!=second)
        {
            printf("Case %d: impossible\n",I++);
        }
        else
        {
            int X=abs(x1-x2);
            int Y=abs(y1-y2);
            if(X==Y)
            {
                printf("Case %d: 1\n",I++);
            }
            else
            {
                printf("Case %d: 2\n",I++);
            }
        }
    }
}
