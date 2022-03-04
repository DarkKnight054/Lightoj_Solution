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
struct no{
    ll zero,one,two;
};
no seg[sz * 4];
ll lazy[sz * 4];
no concentate(no a,no b)
{
    return ((no){a.zero+b.zero,a.one+b.one,a.two+b.two});
}
void propagate(int node, int b, int e){
    ll i=seg[node].zero,j=seg[node].one,k=seg[node].two;
//    cout<<b<<" propagate "<<e;endl;
//    cout<<i<<" first "<<j<<" first "<<k;endl;
    if(i||j||k)
    {
        if(lazy[node]==2)seg[node].zero=j,seg[node].one=k,seg[node].two=i;
        else if(lazy[node]==1)seg[node].zero=k,seg[node].one=i,seg[node].two=j;
    }
    else
    {
        if(lazy[node]==0)seg[node].zero=e-b+1;
        else if(lazy[node]==1)seg[node].one=e-b+1;
        else seg[node].two=e-b+1;
    }
//    i=seg[node].zero,j=seg[node].one,k=seg[node].two;
//    cout<<i<<" second "<<j<<" second "<<k;endl;
    if (b != e) {
        lazy[node * 2] += lazy[node];
        lazy[node*2]%=3;
        lazy[node * 2 + 1] += lazy[node];
        lazy[node*2+1]%=3;
    }
    lazy[node] = 0ll;
}
void update(int node, int b, int e, int l, int r, ll val){
    propagate(node, b, e);
    if (b > r || e < l) return;
    if (b >= l && e <= r) {
        ll i=seg[node].zero,j=seg[node].one,k=seg[node].two;
//        cout<<b<<" "<<e;endl;
//        cout<<i<<" first "<<j<<" first "<<k;endl;
        if(i||j||k)seg[node].zero=k,seg[node].one=i,seg[node].two=j;
        else seg[node].one=e-b+1;
//        i=seg[node].zero,j=seg[node].one,k=seg[node].two;
//        cout<<i<<" second "<<j<<" second "<<k;endl;
        if (b != e) {
            lazy[node * 2] += val;
            lazy[node*2]%=3;
            lazy[node * 2 + 1] += val;
            lazy[node*2+1]%=3;
        }
        return;
    }
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    seg[node]=concentate(seg[node*2],seg[node*2+1]);
}
no query(int node, int b, int e, int l, int r){
    propagate(node, b, e);
    if (b > r || e < l) return ((no){0,0,0});
    if (b >= l && e <= r) return seg[node];
    return concentate(query(node * 2, b, mid, l, r),query(node * 2 + 1, mid + 1, e, l, r));
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m,q,num;
    in(n);in(q);
    ms(seg,0);
    ms(lazy,0);
    printf("Case %lld:\n",cas++);
    while(q--)
    {
        no ans;
        in(num);in(k);in(l);
        k++,l++;
        if(!num)update(1,1,n,k,l,1);
        else {ans=query(1,1,n,k,l);
        out(ans.zero);endl;}
    }
    }
}
