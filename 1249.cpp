#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("c.txt","w",stdout);
	int t;
	cin>>t;
	string str;
	int x,y,z;
	int I=1;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,string> > a;
		while(n--)
		{
			cin>>str>>x>>y>>z;
			a.push_back(make_pair((x*y*z),str));
		}
		sort(a.begin(),a.end());
		if(a[0].first==a[a.size()-1].first)
		{
			printf("Case %d: no thief\n",I++);
		}
		else
		{
			printf("Case %d: %s took chocolate from %s\n",I++,a[a.size()-1].second.c_str(),a[0].second.c_str());
		}
	}
}
