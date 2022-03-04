#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%d",&x)
#define Lin(x) scanf("%lld",&x)
#define out(x) printf("%d",x)
#define Lout(x) printf("%lld",x)
#define sps printf(" ")
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define INF 1e9
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define MAX 1005
int arr[MAX];
int sum;
vector<int>adj[MAX];
bool visit[MAX];
pii bfs(int sorce)
{
    int taka=arr[sorce],lok=1,i,cur,now;
    queue<int>q;
    q.push(sorce);
    visit[sorce]=true;
//    cout<<taka<<" mile jabe ki sorce ? "<<sorce<<" orginal "<<arr[sorce];endl;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(i=0;i<adj[cur].size();i++)
        {
            now=adj[cur][i];
            if(!visit[now])
            {
//                cout<<taka<<" mile jabe ki ? "<<now<<" orginal "<<arr[now];endl;
                taka+=arr[now];
                lok++;
                q.push(now);
                visit[now]=true;
            }
        }
    }
    return {lok,taka};
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m,u,v;
    in(n);in(m);
    for(i=1;i<=n;i++)in(arr[i]);
    pii cur;
    for(i=0;i<m;i++)
    {
        in(u);in(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ms(visit,false);
    sum=-1;
    for(i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            cur=bfs(i);
            //cout<<i<<" "<<cur.Y<<" "<<cur.X<<" "<<cur.Y%cur.X;endl;
            if(cur.Y%cur.X){sum=-1;break;}
            else k=cur.Y/cur.X;
            if(sum==-1)sum=k;
            else if(sum!=k){sum=-1;break;}
        }
    }
    printf("Case %d: ",cas++);
    if(sum==-1)puts("No");
    else puts("Yes");
    for(i=1;i<=n;i++)adj[i].clear();
    }
    return 0;
}
