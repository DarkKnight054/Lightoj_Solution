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
#define MAX 505
#define INF 9223372036854775807LL
#define MOD 1000000007
#define print(cs) printf("Case %lld:\n",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b){return ((a*b)/__gcd(a,b));}
ll par[MAX];
ll level[MAX];
vector< pii >adj[MAX];
ll Find(ll node)
{
    return (par[node]==node?node:par[node]=Find(par[node]));
}
void bfs(ll sorce)
{
    level[sorce]=0;
    priority_queue< pair< pii,ll >,vector< pair<pii,ll> >,greater< pair<pii,ll> > >pq;
    ll i,j,k,l,n,m,r,u,v;
    for(i=0; i<adj[sorce].size(); i++)pq.push({adj[sorce][i],sorce});
    while(!pq.empty())
    {
        pair<pii,ll> poo=pq.top();
        pq.pop();
        u=Find(poo.X.Y);
        v=Find(poo.Y);
        if(u!=v)
        {
            par[poo.X.Y]=v;
            level[poo.X.Y]=max(level[poo.Y],poo.X.X);
            for(i=0; i<adj[u].size(); i++)pq.push({adj[u][i],u});
        }
    }
}
void init()
{
    for(ll i=0; i<MAX; i++)
    {
        adj[i].clear();
        par[i]=i;
        level[i]=INF;
    }
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,u,v,k,w,l,n,m,r;
        init();
        in(n);
        in(m);
        for(i=0; i<m; i++)
        {
            in(u);
            in(v);
            in(w);
            u++,v++;
            adj[u].pb({w,v});
            adj[v].pb({w,u});
        }
        ll des;
        in(des);
        des++;
        bfs(des);
        print(cas++);
        for(i=1; i<=n; i++)
        {
            if(level[i]==INF)puts("Impossible");
            else
            {
                out(level[i]);
                endl;
            }
        }
    }
    return 0;
}
