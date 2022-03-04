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
#define MAX 100005
vector<ll>adj[MAX];
bool visit[MAX];
stack<ll>toposort;
void dfs1(ll node)
{
    visit[node]=true;
    for(ll i=0;i<adj[node].size();i++)
    {
        ll u=adj[node][i];
        if(!visit[u])dfs1(u);
    }
    toposort.push(node);
}
void dfs2(ll node)
{
    visit[node]=true;
    for(ll i=0;i<adj[node].size();i++)
    {
        ll u=adj[node][i];
        if(!visit[u])dfs2(u);
    }
}
ll solve(ll n)
{
    ll i;
    ms(visit,false);
    for(i=1;i<=n;i++)
        if(!visit[i])dfs1(i);
    ms(visit,false);
    ll cnt=0;
    while(!toposort.empty())
    {
        ll u=toposort.top();
        toposort.pop();
        if(!visit[u])cnt++,dfs2(u);
    }
    for(i=1;i<=n;i++)adj[i].clear();
    return cnt;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,u,v;
        in(n);in(m);
        while(m--)
        {
            in(u);in(v);
            adj[u].pb(v);
        }
        k=solve(n);
        printf("Case %lld: %lld\n",cas++,k);
    }
}
