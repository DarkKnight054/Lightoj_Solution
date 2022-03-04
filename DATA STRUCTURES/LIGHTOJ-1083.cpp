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
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define MAX 30005
ll tree[3*MAX],ans=0;
ll arr[MAX];
void build(ll node,ll b,ll  e)
{
    if(b==e)
    {
        tree[node]=b;
        return ;
    }
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;
    build(left,b,mid);
    build(right,mid+1,e);
    if(arr[tree[left]]<=arr[tree[right]])tree[node]=tree[left];
    else tree[node]=tree[right];
}
ll query(ll node,ll b,ll e,ll i,ll j)
{
    if(j<b||e<i)return -1;
    if(b>=i&&e<=j)return tree[node];
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;
    ll p1=query(left,b,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
//    cout<<i<<" "<<j<<" "<<p1<<" "<<p2;endl;
    if(p1==-1)return p2;
    else if(p2==-1)return p1;
    else
    {
        if(arr[p1]<arr[p2])return p1;
        else return p2;
    }
}
void fn(ll i,ll j,ll n)
{
    if(i>j||i<0||i>n||j<0||j>n)return;
    if(i==j)
    {
        ans=max(ans,arr[i]);
        return ;
    }
    else
    {
        ll idx=query(1,1,n,i,j);
        ans=max(ans,(j-i+1)*arr[idx]);
        fn(idx+1,j,n);
        fn(i,idx-1,n);
    }
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m;
    in(n);
    ans=0;
    for(i=1;i<=n;i++)in(arr[i]);
    build(1,1,n);
    fn(1,n,n);
    printf("Case %lld: ",cas++);
    out(ans);endl;
    }
    return 0;
}
