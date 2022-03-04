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
#define MAX 100005
#define INF 92233720368547758LL
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll tree[3*MAX];
void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        tree[node]=1LL;
        return ;
    }
    ll left = (node<<1LL);
    ll right = left+1;
    ll mid = (b+e)>>1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
ll query1(ll node,ll b,ll e,ll val)
{
    if(b==e)
    {
        return b;
    }
    ll left = (node<<1LL);
    ll right = left+1;
    ll mid = (b+e)>>1;
    if(tree[right]>=val)return query1(right,mid+1,e,val);
    else return query1(left,b,mid,val-tree[right]);
}
void query2(ll node,ll b,ll e,ll val)
{
    if(b>val||e<val)return ;
    if(b==e&&b==val)
    {
        tree[node]=0LL;
        return;
    }
    ll left = (node<<1LL);
    ll right = left+1;
    ll mid = (b+e)>>1;
    query2(left,b,mid,val);
    query2(right,mid+1,e,val);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    ll test;
    in(test);
    ll cas = 1LL;
    while(test--)
    {
        ll i,j,k,l,n,m,r;
        in(n);
        build(1LL,1LL,n);
        ll arr[n];
        for(i=0;i<n;i++)
        {
            in(arr[i]);
        }
        for(i=n-1;i>=0;i--)
        {
            k = query1(1LL,1LL,n,arr[i]+1);
            query2(1LL,1LL,n,k);
        }
        print(cas++);
        out(k);endl;
    }
}
