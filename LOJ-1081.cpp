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
#define MAX 200005
#define INF  9223372036854775807
#define MOD 998244353
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll x,ll y){return((x/__gcd(x,y))*y);}
ll arr[505][505];
ll sparse_table[505][505][9];
void build(ll n,ll m)
{
    ll i,j,k,l,r;
    for(i=1;i<=n;i++)
    {
        for(k=0;k<=8;k++)
        {
            for(j=1;j+(1<<k)-1<=m;j++)
            {
                if(!k)
                {
                    sparse_table[i][j][k] = arr[i][j];
                    continue;
                }
                sparse_table[i][j][k] = max(sparse_table[i][j][k-1],sparse_table[i][j+(1<<(k-1))][k-1]);            
            }
        }
    }
}
ll query(ll l,ll r,ll td)
{
    ll ans = -1;
    ll k = log2(td);
    for(ll i = l;i<=l+td-1;i++)
    {
        ans = max(ans,max(sparse_table[i][r][k],sparse_table[i][r+td-(1<<k)][k]));
    }
    return ans;
}
int main()
{
    ll test=1LL,cas=0;
    cin>>test;
    while(test--)
    {
        ll i,j,k,l,n,m,r,q;
        in(n);in(q);
        m=n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                in(arr[i][j]);
            }
        }
        build(n,m);
        printf("Case %lld: \n",++cas);
        while(q--)
        {
            in(l);in(r);in(m);
            out(query(l,r,m));endl;
        }
    }
}
