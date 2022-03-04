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
#define MAX 55
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
ll mat[MAX][MAX];
void init()
{
    for(ll i=0;i<MAX;i++)par[i]=i;
    edge.clear();
}
ll Find(ll node){return (par[node]==node?node:par[node]=Find(par[node]));}
ll mst(ll n)
{
    ll i,j,k,l,m,r,mot=0,cnt=0;
    sort(all(edge),cmp);
    for(i=0;i<edge.size();i++)
    {
        ll u=Find(edge[i].u);
        ll v=Find(edge[i].v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            mot+=edge[i].w;
            if(cnt==n-1)break;
        }
    }
    return (cnt==n-1?mot:-1);
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,u,v,w;
        in(n);
        init();
        ll sum=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                in(mat[i][j]);
                if(!mat[i][j])continue;
                block temp;
                sum+=mat[i][j];
                temp.u=i,temp.v=j,temp.w=mat[i][j];
                edge.pb(temp);
            }
        }
        ll cot=mst(n);
        cot=(cot==-1?cot:sum-cot);
        print(cas++);
        out(cot);endl;
    }
}
