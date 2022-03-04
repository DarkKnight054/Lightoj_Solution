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
#define MAX 12
ll dp[2][2][12][100][100];
vector<ll>inp;
ll lim,mod;
ll mul(ll x,ll d)
{
    while(x--)
    {
        d*=10LL;
        d%=mod;
    }
    return d;
}
ll fn(ll issmall,ll isstart,ll pos,ll val,ll  sum)
{
    if(pos==lim)
    {
        val%=mod;
        sum%=mod;
        if(val==0&&sum==0)
            return 1LL;
        else
            return 0LL;
    }
    if(dp[issmall][isstart][pos][val][sum]!=-1)
        return dp[issmall][isstart][pos][val][sum];
    ll ret=0,i,k;
    k = issmall ? 9LL : inp[pos];
    if( ! isstart )
    {
        for(i=0; i<=k; i++)
        {
            ll m = (val+mul(lim-pos-1,i))%mod;
            ret += fn( issmall|i<inp[pos] , 0 , pos+1 , m , (sum+i)%mod);
        }
    }
    else
    {
        for(i=1; i<=k; i++)
        {
            ll m=(val+mul(lim-pos-1,i))%mod;
            ret += fn(issmall|i<inp[pos],0,pos+1,m,(sum+i)%mod);
        }
        ret+=fn(1,1,pos+1,0,0);
    }
    return dp[issmall][isstart][pos][val][sum]=ret;
}
ll call(ll x)
{
    if(x<0)
        return 0;
    ms(dp,-1);
    inp.clear();
    while(x)
    {
        inp.pb(x%10);
        x/=10;
    }
    lim=inp.size();
    reverse(inp.begin(),inp.end());
    return fn(0,1,0,0,0);
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,k,l,n,m;
        in(n);
        in(m);
        in(mod);
        if(mod>99)
            k=0;
        else k=call(m)-call(n-1);
        printf("Case %lld: %lld\n",cas++,k);
    }
}
