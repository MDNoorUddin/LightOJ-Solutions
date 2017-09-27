#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("c.txt","w",stdout);
    int t;
    cin>>t;
    int casE=1,value;
    string str;
    while(t--)
    {
        int sizE,commands;
        cin>>sizE>>commands;
        printf("Case %d:\n",casE++);
        deque<int> x;
        while(commands--){
        cin>>str;
        if(str=="pushLeft"||str=="pushRight")
        {
            cin>>value;
            if(x.size()==sizE)
            {
                cout<<"The queue is full\n";
            }
            else{
                if(str=="pushLeft"){
                    x.push_front(value);
                    printf("Pushed in left: %d\n",value);
                }
                else{
                    x.push_back(value);
                    printf("Pushed in right: %d\n",value);
                }
            }
        }
        else{
            if(x.empty())
                cout<<"The queue is empty\n";
            else{
                if(str=="popLeft")
                {
                    printf("Popped from left: %d\n",x.front());
                    x.pop_front();
                }
                else
                {
                    printf("Popped from right: %d\n",x.back());
                    x.pop_back();
                }
            }
        }
        }
    }
    return 0;
}
