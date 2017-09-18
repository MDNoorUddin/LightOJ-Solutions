#include<iostream>
using namespace std;
int main()
{
    long long number;
    int reminder;
    int t;
    cin>>t;
    for(int x=1;x<=t;x++){
    cin>>number;
    long long count=0;
    while(number!=0)
    {
        reminder=number%2;
        if(reminder==1)
            count++;
        number=number/2;
 
    }
    if(count%2==0)
        cout<<"Case "<<x<<": even\n";
        else
        cout<<"Case "<<x<<": odd\n";
 
}
return 0;
}
