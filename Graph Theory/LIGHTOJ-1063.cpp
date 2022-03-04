#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<ll,ll> pii;
#define pb push_back
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld",x)
#define X first
#define Y second
#define sps printf(" ")
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define all(v) v.begin(),v.end()
#define dis(it,it1) distance(it,it1)+1
#define MAX 10005
#define INF 9223372036854775807LL
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
bool visit[MAX];
vector<ll>adj[MAX];
ll arti_point[MAX];
ll timer=0;
ll low[MAX],dis[MAX];
void articulation(ll node,ll par)
{
    visit[node]=true;
    low[node]=dis[node]=timer++;
    ll child=0;
    for(ll i=0;i<adj[node].size();i++)
    {
        ll u=adj[node][i];
        if(u==par)continue;
        if(visit[u])
        {
            low[node]=min(low[node],dis[u]);
        }
        else
        {
            articulation(u,node);
            low[node]=min(low[node],low[u]);
            ++child;
            if(low[u]>=dis[node]&&par!=-1)
                arti_point[node]=1;
        }
    }
    if(child>1&&par==-1)
        arti_point[node]=1;
}
void init()
{
    ms(visit,false);
    for(ll i=0;i<MAX;i++)adj[i].clear();
    ms(arti_point,0LL);
    timer=0;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,u,v,r;
        in(n);in(m);
        init();
        for(i=0;i<m;i++)
        {
            in(u);in(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        for(i=1;i<=n;i++)
        {
            if(!visit[i])timer=0,articulation(i,-1);
        }
        print(cas++);
        ll cnt=0;
        for(i=0;i<MAX;i++)if(arti_point[i])cnt++;
        out(cnt);endl;
    }
}
