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
#define MAX 20005
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
//        cout<<i<<" "<<visit[i];endl;
        if(!visit[i])dfs(i);
    }
    return mark;
}
ll in_degree[MAX],out_degree[MAX];
void last_dfs(ll node)
{
    visit[node]=true;
    for(ll i=0;i<adj[node].size();i++)
    {
        ll u=adj[node][i];
        in_degree[u]++;
        out_degree[node]++;
        last_dfs(u);
    }
}
void solve(ll n)
{
    ll i,j,k,l,m,r;
    if(n==1)
    {
        cout<<"0\n";
        return ;
    }
    ms(visit,false);
    for(i=0;i<n;i++)
    {
        if(!visit[i])last_dfs(i);
    }
    ll x=0,y=0;
    for(i=0;i<n;i++)
    {
//        cout<<component[i].size()<<" "<<i<<" "<<in_degree[i]<<" "<<out_degree[i];endl;
//        for(ll po:component[i])cout<<po<<" ";
        if(!in_degree[i])x++;
        if(!out_degree[i])y++;
    }
    cout<<max(x,y);endl;
}
void init()
{
    compo.clear();
    for(ll i=0;i<MAX;i++)
    {
        in_degree[i]=0;
        out_degree[i]=0;
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
        in(n);in(m);
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
