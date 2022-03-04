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
#define MAX 205
#define INF 9223372036854775807LL
#define MOD 1000000007
#define print(cs) printf("Case %lld:\n",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
struct block{
ll u,v,w;
bool operator<(const block& p) const
{
    if(w!=p.w)return w < p.w;
    else if(v!=p.v)return v<p.v;
    else return u<p.u;
}
};
set<block>edge;
ll par[MAX];
ll Find(ll node){return (par[node]==node?node:par[node]=Find(par[node]));}
ll mst(ll n)
{
    ll i,j,k,l,m,r,mot=0,cnt=0;
    for(i=0;i<=n;i++)par[i]=i;
    for(block temp:edge)
    {
        ll u=Find(temp.u);
        ll v=Find(temp.v);
//        cout<<temp.u<<" "<<temp.v<<" "<<temp.w<<" "<<cnt;endl;
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            mot+=temp.w;
            if(cnt==n-1)break;
        }
    }
    return (cnt==n-1?mot:-1);
}
int main()
{
    ll test,cas=1LL;
    in(test);
    while(test--)
    {
        ll cost,i,j,k,l,n,m,u,v,r,w;
        in(n);in(m);
        print(cas++);
        for(i=0;i<m;i++)
        {
            block temp;
            in(u);in(v);in(w);
            temp.u=u,temp.v=v,temp.w=w;
            edge.insert(temp);
//            cout<<edge.size();endl;
            ll ans=mst(n);
            out(ans);endl;
        }
        edge.clear();
    }
}
