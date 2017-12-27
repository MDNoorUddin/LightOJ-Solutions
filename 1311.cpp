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

int main(int argc, char** argv) {
	
	//freopen("c.txt","w",stdout);
	int t;
	int I=1;
	cin>>t;
	double v1,v2,a1,a2,v3;
	double d1,d2,d;
	while(t--){
	cin>>v1>>v2>>v3>>a1>>a2;
	d1=(v1*v1)/(2*a1);
	d2=(v2*v2)/(2*a2); 
	d=d1+d2;
	double t1,t2,t;
	t1=v1/a1;
	t2=v2/a2;
	t=max(t1,t2);
	t=t*v3;
	printf("Case %d: %.10lf %.10lf\n",I++,d,t);
    }
	ret 0;
}
