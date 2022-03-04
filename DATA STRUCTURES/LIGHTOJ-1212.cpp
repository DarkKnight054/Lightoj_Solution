#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,t,j,c,d,e,f,g,h,u,o,n,m;
    string x="pushLeft",y="pushRight",a="popLeft",b="popRight",v;
    cin>>t;
    for(i=1;i<=t;i++)
    {
          deque<int>q;
        cin>>n>>m;
        printf("Case %d:\n",i);
      for(j=0;j<m;j++)
      {
          cin>>v;
          if(v==x)
            {
//                  cout<<q.size()<<endl;
                cin>>o;
                if(q.size()==n)cout<<"The queue is full\n";
                else{cout<<"Pushed in left: "<<o<<'\n';
                q.push_front(o);}
            }
            else if(v==y)
            {
                cin>>o;
//                 cout<<q.size()<<endl;
                if(q.size()==n)cout<<"The queue is full\n";
                else {cout<<"Pushed in right: "<<o<<'\n';
                q.push_back(o);}
            }
            else if(v==a)
            {
//                 cout<<q.size()<<endl;
           if(q.size()==0)cout<<"The queue is empty\n";
                else{cout<<"Popped from left: "<<q.front()<<'\n';
                q.pop_front();}
            }
            else if(v==b)
            {
                if(q.size()==0)cout<<"The queue is empty\n";
                else{cout<<"Popped from right: "<<q.back()<<'\n';
                q.pop_back();}
            }
      }
    }
    return 0;
}
