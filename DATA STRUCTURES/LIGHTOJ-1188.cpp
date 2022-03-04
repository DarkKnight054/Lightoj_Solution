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
#define MAX 100005
ll K, ans[MAX], arr[MAX], sum,brr[MAX];
struct Query{
    ll index, L, R;
    bool operator < (const Query &other) const {
		ll block_own = L/K;
		ll block_other = other.L/K;
		if(block_own == block_other)
            return R < other.R;
		return block_own < block_other;
	}
}query[MAX];
void add(ll idx)
{
    brr[arr[idx]]++;
    if(brr[arr[idx]]==1)sum++;
}
void remov(ll idx)
{
    brr[arr[idx]]--;
    if(brr[arr[idx]]==0)sum--;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,n,m,q;
    in(n);in(q);
    ms(brr,0);
    K=sqrt(n);
    for(i=1;i<=n;i++)in(arr[i]);
    for(i=0;i<q;i++)
    {
        in(query[i].L);in(query[i].R);
        query[i].index=i+1;
    }
    sort(query,query+q);
    ll l=1,r=0;
    sum=0;
    for(i=0;i<q;i++)
    {
        while(r<query[i].R)add(++r);
        while(l<query[i].L)remov(l++);
        while(r>query[i].R)remov(r--);
        while(l>query[i].L)add(--l);
//        cout<<l<<" "<<r;endl;
        ans[query[i].index]=sum;
    }
    printf("Case %d:\n",cas++);
    for(i=1;i<=q;i++)
    {
        out(ans[i]);endl;
    }
    }
}
