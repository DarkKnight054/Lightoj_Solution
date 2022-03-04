#include <bits/stdc++.h>
using namespace std;
#define ll int
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<ll,ll> pii;
#define pb push_back
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define X first
#define Y second
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define MAX 100005
struct node{
ll sum,prop;};
void update(node tree[],ll node,ll b,ll e,ll i,ll j,ll x)
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
    update(tree,left,b,mid,i,j,x);
    update(tree,right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(node tree[],ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(j<b||e<i)return 0;
    if(b>=i&&e<=j)
        return tree[node].sum+(e-b+1)*carry;
    ll left=node<<1;
    ll right=(node<<1)+1;
    ll mid=(b+e)>>1;
    ll p1=query(tree,left,b,mid,i,j,carry+tree[node].prop);
    ll p2=query(tree,right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
    string s;
    cin>>s;
    ll i,j,k,l,n,m,q;
    q=s.size();
    node tree[3*q+5];
    ms(tree,0);
    char c,g;
    in(n);
    printf("Case %d:\n",cas++);
    while(n--)
    {
        cin>>c;
        if(c=='I')
        {
            in(k);in(l);
            update(tree,1,1,q,k,l,1);
        }
        else
        {
            in(k);
            m=query(tree,1,1,q,k,k,0);
//            cout<<m;endl;
            if(m&1)
            {
                if(s[k-1]=='0')puts("1");
                else puts("0");
            }
            else printf("%c\n",s[k-1]);
        }
    }
    }
    return 0;
}
