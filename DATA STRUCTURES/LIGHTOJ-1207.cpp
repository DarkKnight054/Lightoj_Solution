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
const int sz = 200005;
ll seg[sz * 4], lazy[sz * 4];
void propagate(int node, int b, int e){
    seg[node] += lazy[node] * (e - b + 1);
    if (b != e) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0ll;
}
void update(int node, int b, int e, int l, int r, ll val){
    propagate(node, b, e);
    if (b > r || e < l) return;
    if (b >= l && e <= r) {
        seg[node] += val * (e - b + 1);
        if (b != e) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    seg[node] = min(seg[node * 2] , seg[node * 2 + 1]);
}
ll query(int node, int b, int e, int l, int r){
    propagate(node, b, e);
    if (b > r || e < l) return 1;
    if (b >= l && e <= r) return seg[node];
    return min(query(node * 2, b, mid, l, r),query(node * 2 + 1, mid + 1, e, l, r));
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ms(seg,0);
        ms(lazy,0);
        ll i,j,k,l,n,m=0,r;
    in(n);
    vector< pii >point;
    for(i=0;i<n;i++)
    {
        in(l);in(r);
        point.pb({l,r});
        m=max(m,r);
    }
    ll ans=0;
    for(i=n-1;i>=0;i--)
    {
        if(!query(1,1,m,point[i].X,point[i].Y))
        {
            ans++;
            update(1,1,m,point[i].X,point[i].Y,1);
        }
    }
    printf("Case %lld: ",cas++);
    out(ans);endl;
    }
}
