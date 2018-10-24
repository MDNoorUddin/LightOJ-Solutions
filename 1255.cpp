#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

#define MAX 999999999999
#define MIN -99999999999

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,I=1;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int count=0;
        std::size_t found = a.find(b,0);
        while(found!=std::string::npos){
            count++;
            found = a.find(b,found+1);
        }
        //std::cout << "first 'needle' found at: " << found << '\n';
        printf("Case %d: %d\n",I++,count);
    }
}
