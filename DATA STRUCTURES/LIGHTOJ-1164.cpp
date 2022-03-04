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
#define MAX 100005
struct node{
ll sum,prop;};
node tree[3*MAX];
void update(ll node,ll b,ll e,ll i,ll j,ll x)
{
    if(j<b||e<i)return ;
    if(b>=i&&e<=j)
    {
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return ;
    }
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(j<b||e<i)return 0;
    if(b>=i&&e<=j)
        return tree[node].sum+(e-b+1)*carry;
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;
    ll p1=query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,q;
        in(n);in(q);
        ms(tree,0);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            in(j);
            if(!j)
            {
                in(k);in(l);in(m);
                k++,l++;
                update(1,1,n,k,l,m);
            }
            else
            {
                in(k);in(l);
                k++,l++;
                cout<<query(1,1,n,k,l,0);endl;
            }
        }
    }
    return 0;
}
