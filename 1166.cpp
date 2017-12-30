#include <iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<math.h>
#include<string>
#include<list>


using namespace std;


#define ll long long
#define input scanf
#define output printf 
#define Loop while
#define echo cout
#define ret return
#define MAX 999999999999999999
#define MIN 0
#define PI 3.1415

vector<int> s(100);
void sort()
{
	for(int i=0;i<100;i++)
	s[i]=i+1;
	return;
}
int main(int argc, char** argv) {
	
	//freopen("c.txt","w",stdout);
	sort();
	int t,n,I=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		vector<int> b(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(b[i]!=s[i])
			{
				for(int j=i+1;j<n;j++)
				{
					if(b[j]==s[i])
					{
						//cout<<"swap "<<b[i]<<" "<<b[j]<<endl;
						swap(b[j],b[i]);
						count++;
						break;
					}
				}
			}
		}
		printf("Case %d: %d\n",I++,count);
	}
	return 0;
}
