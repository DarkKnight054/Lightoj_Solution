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
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b){return ((a*b)/__gcd(a,b));}
struct block{
ll u,v,w;
};
vector<block>edge_max,edge_min;
ll par[MAX];
bool cmp1(block a,block b){return a.w<b.w;}
bool cmp2(block a,block b){return a.w>b.w;}
ll Find(ll node)
{
    return (par[node]==node?node:par[node]=Find(par[node]));
}
pii mst(ll n)
{
    sort(all(edge_max),cmp2);
    sort(all(edge_min),cmp1);
    ll cnt=0,mx=0,mn=0;
    for(ll i=0;i<edge_max.size();i++)
    {
        ll u=Find(edge_max[i].u);
        ll v=Find(edge_max[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            mx+=edge_max[i].w;
            if(cnt==n-1)break;
        }
    }
    for(ll i=0;i<MAX;i++)par[i]=i;
    cnt=0;
    for(ll i=0;i<edge_min.size();i++)
    {
        ll u=Find(edge_min[i].u);
        ll v=Find(edge_min[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            mn+=edge_min[i].w;
            if(cnt==n-1)break;
        }
    }
    return {mn,mx};
}
void init()
{
    edge_max.clear();
    edge_min.clear();
    for(ll i=0;i<MAX;i++)par[i]=i;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,r,u,v,w;
        in(n);
        n++;
        init();
        while(scanf("%lld %lld %lld",&u,&v,&w))
        {
            if(!u&&!v&&!w)break;
            u++,v++;
            block temp;
            temp.u=u;
            temp.v=v;
            temp.w=w;
            edge_max.pb(temp);
            edge_min.pb(temp);
        }
        pii po=mst(n);
        ll mot=po.X+po.Y;
        print(cas++);
        if(mot&1)printf("%lld/2",mot);
        else out(mot/2);
        endl;
    }
}
