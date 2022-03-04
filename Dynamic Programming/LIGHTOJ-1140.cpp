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
#define MAX 35
ll dp[2][2][MAX][MAX];
vector<ll>inp;
ll lim;
ll fn(ll issmall,ll isstart,ll pos,ll val)
{
    if(pos==lim)
        return val;
    if(dp[issmall][isstart][pos][val]!=-1)
        return dp[issmall][isstart][pos][val];
    ll ret=0,i,k;
    k=issmall?9LL:inp[pos];
    if(!isstart)
    {
        for(i=0; i<=k; i++)
            ret+=fn(issmall|i<inp[pos],isstart,pos+1,(i==0)+val);
    }
    else
    {
        for(i=1; i<=k; i++)
            ret+=fn(issmall|i<inp[pos],0,pos+1,(i==0)+val);
        ret+=fn(1,1,pos+1,0);
    }
    return dp[issmall][isstart][pos][val]=ret;
}
ll call(ll x)
{
    if(x<0)return 0;
    if(x<=9)return 1LL;
    ms(dp,-1);
    inp.clear();
    while(x)
    {
        inp.pb(x%10);
        x/=10;
    }
    lim=inp.size();
    reverse(inp.begin(),inp.end());
    return fn(0,1,0,0)+1;
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
        k=call(m)-call(n-1);
        printf("Case %lld: %lld\n",cas++,k);
    }
}
