#include<iostream>
using namespace std;
int main(){
     int t;
     cin>>t;
     for(int i=1;i<=t;i++){
          int n;
          cin>>n;
          int money=0;
          cout<<"Case "<<i<<":\n";
          while(n--){
              string x;
              cin>>x;
              if(x[0]=='d')
                 {
                    int g;
                    cin>>g;
                    money+=g;
                  }
               else
                 cout<<money<<endl;
         }
     }
     return 0;
}
