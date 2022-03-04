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
#define sps printf(" ");
#define X first
#define Y second
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define mid ((b+e)/2)
const int sz = 100005;
ll seg[sz * 4], lazy[sz * 4];
ll arr[sz];
void propagate(int node, int b, int e)
{
    if(lazy[node]!=-1)
        seg[node] = lazy[node] * (e - b + 1);
    if (b != e)
    {
        if(lazy[node]!=-1)
            lazy[node * 2] = lazy[node];
        if(lazy[node]!=-1)
            lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] =-1ll;
}
void update(int node, int b, int e, int l, int r, ll val)
{
    propagate(node, b, e);
    if (b > r || e < l)
        return;
    if (b >= l && e <= r)
    {
        seg[node] = val * (e - b + 1);
        if (b != e)
        {
            lazy[node * 2] = val;
            lazy[node * 2 + 1] = val;
        }
        return;
    }
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    /*cout<<b<<" LEFT "<<mid;endl;
    cout<<seg[node*2]<<" "<<lazy[node*2];endl;
    cout<<mid+1<<" RIGHT "<<e;endl;
    cout<<seg[node*2+1]<<" "<<lazy[node*2+1];endl;*/
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(int node, int b, int e, int l, int r)
{
    propagate(node, b, e);
    if (b > r || e < l)
        return 0ll;
    if (b >= l && e <= r)
        return seg[node];
    return query(node * 2, b, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ms(seg,0);
        ms(lazy,-1);
        ll q,i,j,k,l,n,m,x;
        in(n);
        in(q);
        printf("Case %lld:\n",cas++);
        while(q--)
        {
            in(m);
            if(m==1)
            {
                in(k);
                in(l);
                in(x);
                k++,l++;
                update(1,1,n,k,l,x);
            }
            else
            {
                in(k);
                in(l);
                k++,l++;
                j=query(1,1,n,k,l);
                m=__gcd(j,l-k+1);
                x=(l-k+1)/m;
                j/=m;
                printf("%lld",j);
                if(x>1)
                    printf("/%lld",x);
                puts("");
            }
        }
    }
    return 0;
}
