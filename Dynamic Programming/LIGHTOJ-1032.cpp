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
ll dp[2][2][MAX][MAX][2];
vector<ll>inp;
ll fn(ll issmall,ll isstart,ll pos,ll val,ll prev_bit)
{
//    cout<<pos<<" "<<val<<" fn opening "<<prev_bit;endl;
    if(pos==32)return val;
    if(dp[issmall][isstart][pos][val][prev_bit]!=-1)
        return dp[issmall][isstart][pos][val][prev_bit];
    ll ret=0,i,k;
    k = issmall ? 1LL : inp[pos];
    if( ! isstart )
    {
        for(i=0; i<=k; i++)
        {
            if(i==1)
            {
                if(prev_bit==i)ret+=fn(issmall|i<inp[pos],0,pos+1,val+1,1);
                else ret+=fn(issmall|i<inp[pos],0,pos+1,val,i);
            }
            else ret+=fn(issmall|i<inp[pos],0,pos+1,val,i);
        }
    }
    else
    {
        for(i=1; i<=k; i++)
        {
            ret += fn(issmall|i<inp[pos],0,pos+1,val,i);
        }
        ret+=fn(1,1,pos+1,0,0);
    }
//    cout<<pos<<" "<<val<<" fn returning "<<prev_bit<<" "<<ret;endl;
    return dp[issmall][isstart][pos][val][prev_bit]=ret;
}
ll call(ll x)
{
    if(x<=0)
        return 0;
    ms(dp,-1);
    inp.clear();
    ll i;
    for(i=0;i<=31;i++)
    {
        inp.pb((x>>i)&1);
    }
    reverse(inp.begin(),inp.end());
    ll start;
    for(i=0;i<=31;i++)
    {
        if(inp[i]==1)
        {
            start=i;
            break;
        }
    }
    ll ans=fn(0,1,start,0,0);
    return ans;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,k,l,n,m;
        in(n);
        k=call(n);
        printf("Case %lld: %lld\n",cas++,k);
    }
}
