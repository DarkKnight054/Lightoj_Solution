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
#define MAX 100000007
ll make;
vector<ll>coin,cnt;
ll dp[51][1005];
ll occur(ll idx,ll n,ll amount)
{
    if(idx==n)
    {
        if(amount==make)return 1;
        else return 0;
    }
    if(dp[idx][amount]!=-1)return dp[idx][amount];
    ll ret1=0,i;
    for(i=0;i<=cnt[idx];i++)
    {
        if(amount+i*coin[idx]<=make)ret1+=occur(idx+1,n,amount+(i*coin[idx]));
        ret1%=MAX;
    }
    return dp[idx][amount]=ret1;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m;
    in(n);in(make);
    for(i=0;i<n;i++)
    {
        in(j);
        coin.pb(j);
    }
    for(i=0;i<n;i++)
    {
        in(j);
        cnt.pb(j);
    }
    ms(dp,-1);
    printf("Case %lld: ",cas++);
    cout<<occur(0,n,0);endl;
    coin.clear();
    cnt.clear();
    }
    return 0;
}
