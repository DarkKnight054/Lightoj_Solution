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
struct block{
ll u,v,w;
};
bool cmp(block a,block b){return a.w<b.w;}
vector<block>edge;
ll par[MAX];
map<ll,ll>airport;
void init()
{
    for(ll i=0;i<MAX;i++)par[i]=i;
    edge.clear();
    airport.clear();
}
ll Find(ll node){return (par[node]==node?node:par[node]=Find(par[node]));}
pii mst(ll cost)
{
    ll i,j,k,l,m,r,mot=0,cnt=0;
    sort(all(edge),cmp);
    for(i=0;i<edge.size();i++)
    {
        ll u=Find(edge[i].u);
        ll v=Find(edge[i].v);
//        cout<<edge[i].u<<" "<<edge[i].v;endl;
//        cout<<u<<" "<<v;endl;
//        cout<<airport[u]<<" "<<airport[v];endl;
        if(airport[u]==0&&airport[v]==0)airport[v]=1LL,mot+=cost,cnt++;
        if(u!=v)
        {
            if(airport[u]==1&&airport[v]==1)
            {
                if(edge[i].w<cost)
                {
                    par[u]=v;
                    airport[u]=0;
                    cnt--;
                    mot+=edge[i].w-cost;
                }
//                puts("Anal");
            }
            else
            {
                if(edge[i].w>=cost)
                {
                    cnt++;
                    mot+=cost;
                    airport[u]=1LL;
                    airport[v]=1LL;
//                    puts("RUF & TUF");
                }
                else
                {
                    if(airport[v]==1LL)par[u]=v;
                    else par[v]=u;
                    mot+=edge[i].w;
//                    puts("EROTIC");
                }
            }
        }
    }
    return {mot,cnt};
}
int main()
{
    ll test,cas=1LL;
    in(test);
    while(test--)
    {
        ll cost,i,j,k,l,n,m,u,v,r,w;
        in(n);in(m);in(cost);
        init();
        vector<block>pt;
        for(i=1;i<=n;i++)
        {
            block temp;
            temp.u=i,temp.v=i,temp.w=0;
            edge.pb(temp);
        }
        for(i=0;i<m;i++)
        {
            in(u);in(v);in(w);
            block temp;
            temp.u=u,temp.v=v,temp.w=w;
            edge.pb(temp);
        }
        pii po=mst(cost);
        print(cas++);
        cout<<po.X<<" "<<po.Y;endl;
    }
}
