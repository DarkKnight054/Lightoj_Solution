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
#define MAX 50005
vector<ll>edge[MAX],rev_edge[MAX],component[MAX];
stack<ll>st;
bool visit[MAX];
map<ll,ll>compo;
vector<ll>adj[MAX];
void dfs1(ll node)
{
    ll u;
    visit[node]=true;
    for(ll i=0; i<edge[node].size(); i++)
    {
        u=edge[node][i];
        if(!visit[u])
            dfs1(u);
    }
    st.push(node);
}
void dfs2(ll node,ll mark)
{
    component[mark].pb(node);
    compo[node]=mark;
    visit[node]=true;
    for(ll i=0; i<rev_edge[node].size(); i++)
    {
        ll u=rev_edge[node][i];
        if(!visit[u])
            dfs2(u,mark);
    }
}
void dfs(ll node)
{
    visit[node]=true;
    for(ll i=0;i<edge[node].size();i++)
    {
        ll u=edge[node][i];
        if(compo[node]!=compo[u])adj[compo[node]].pb(compo[u]);
        if(!visit[u])dfs(u);
    }
}
ll SCC(ll n)
{
    ll u,v,mark=0,i,j;
    ms(visit,false);
    for(i=1; i<=n; i++)
        if(!visit[i])
            dfs1(i);
    ms(visit,false);
    while(!st.empty())
    {
        u=st.top();
        st.pop();
        if(!visit[u])
        {
            dfs2(u,mark++);
        }
    }
    ms(visit,false);
    for(i=1;i<=n;i++)
    {
        if(!visit[i])dfs(i);
    }
    return mark;
}
ll dp[MAX];
ll rescue(ll node)
{
    visit[node]=true;
    ll ret=component[node].size();
    for(ll i=0;i<adj[node].size();i++)
    {
        ll u=adj[node][i];
        if(!visit[u])ret+=rescue(u);
        else ret+=dp[u];
    }
    return dp[node]=ret;
}
void solve(ll n)
{
    ll idx,i,j,k,l,m,r;
    ms(visit,false);
    ms(dp,-1);
    ll ans=0;
    for(i=0;i<n;i++)
    {
//        cout<<component[i][0]<<" "<<dp[component[i][0]]<<" "<<adj[i].size();endl;
        if(!visit[i])
        {
            l=rescue(i);
            ans=max(ans,dp[i]);
        }
//        cout<<component[i][0]<<" "<<dp[i];endl;
    }
    ll ret=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(dp[i]==ans)
        {
            for(ll po:component[i])ret=min(ret,po);
        }
    }
    cout<<ret;endl;
}
void init()
{
    compo.clear();
    for(ll i=0;i<MAX;i++)
    {
        edge[i].clear();
        adj[i].clear();
        rev_edge[i].clear();
        component[i].clear();
    }
    while(!st.empty())st.pop();
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        init();
        ll i,j,k,l,n,m,r,u,v;
        in(n);
        m=n;
        for(i=0;i<m;i++)
        {
            in(u);in(v);
            edge[u].pb(v);
            rev_edge[v].pb(u);
        }
        k=SCC(n);
//        cout<<k;endl;
        cout<<"Case "<<cas<<": ";cas++;
        solve(k);
    }
}
