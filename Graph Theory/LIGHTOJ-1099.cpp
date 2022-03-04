#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<ll,ll> pii;
#define pb push_back
#define ms(a,b,n) for(ll darkknight=0;darkknight<n;darkknight++)a[darkknight]=b;
#define in(x) scanf("%lld",&x)
#define out(x) printf("%lld",x)
#define X first
#define Y second
#define sps printf(" ")
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define all(v) v.begin(),v.end()
#define dis(it,it1) distance(it,it1)+1
#define MAX 100005
#define INF 9223372036854775807LL
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b){return ((a*b)/__gcd(a,b));}
vector< pii >adj[5005];
vector<ll>dist1(5005,INF),dist2(5005,INF);
void dijkstra()
{
    priority_queue< pii,vector< pii >,greater< pii > >q;
    dist1[(ll)1]=0;
    q.push({dist1[(ll)1],(ll)1});
    while(!q.empty())
    {
        pii cur=q.top(),rec;
        q.pop();
        ll i;
        for(i=0; i<adj[cur.Y].size(); i++)
        {
            rec=adj[cur.Y][i];
            if(dist1[rec.X]>cur.X+rec.Y)
            {
                dist2[rec.X]=dist1[rec.X];
                dist1[rec.X]=cur.X+rec.Y;
                q.push({dist1[rec.X],rec.X});
            }
            else if(dist1[rec.X]<cur.X+rec.Y&&dist2[rec.X]>cur.X+rec.Y)
            {
                dist2[rec.X]=cur.X+rec.Y;
                q.push({dist2[rec.X],rec.X});
            }
        }
    }
}
void init(ll n)
{
    ms(dist1,INF,5005);
    ms(dist2,INF,5005);
    for(ll i=1;i<=n;i++)adj[i].clear();
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,u,v,w;
        in(n);in(m);
        init(n);
        for(i=0;i<m;i++)
        {
            in(u);in(v);in(w);
            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }
        dijkstra();
        print(cas++);
        cout<<dist2[n];endl;
    }
}
