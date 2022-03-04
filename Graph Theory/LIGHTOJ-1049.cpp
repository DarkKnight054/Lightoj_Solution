#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define pp push
#define po pop
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%d",&x)
#define Lin(x) scanf("%lld",&x)
#define out(x) printf("%d",x)
#define Lout(x) printf("%lld",x)
#define sps printf(" ")
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
vector< pii >adj[105];
bool visit[105];
ll ans=0;
void bfs(int sorce,int u)
{
    queue<int>q;
    q.push(sorce);
//    CHECK(sorce);
    while(!q.empty())
    {
        int cur=q.front(),i;
        q.pop();
        for(i=0;i<SZ(adj[cur]);i++)
        {
            pii rec=adj[cur][i];
            if((rec.X==u&&cur==sorce)||(rec.X==sorce&&cur!=u))continue;
            if(!visit[rec.X])
            {
                ans+=rec.Y;
                q.push(rec.X);
                visit[rec.X]=true;
//                cout<<rec.X<<" "<<ans;endl;
            }
        }
    }
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m,u,v,w;
    in(n);
    vector<int>hudai;
    for(i=0;i<n;i++)
    {
        in(u);in(v);in(w);
        if(u==1)hudai.pb(v);
        if(v==1)hudai.pb(u);
        adj[u].pb({v,0});
        adj[v].pb({u,w});
    }
    ms(visit,false);
    ans=0;
    ll ans1=INF;
    bfs(1,hudai[0]);
//    cout<<hudai[0]<<" "<<ans;endl;
    ans1=min(ans,ans1);
    ms(visit,false);
    ans=0;
    bfs(1,hudai[1]);
//    cout<<hudai[1]<<" "<<ans;endl;
    ans1=min(ans,ans1);
    printf("Case %d: ",cas++);
    for(i=1;i<=n;i++)adj[i].clear();
    Lout(ans1);endl;
    }
    return 0;
}
