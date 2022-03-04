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
ll dp[1005],coin[1005];
ll n;
ll fn(ll idx,bool one)
{
    if(idx>=n)return 0;
    if(dp[idx]!=-1)return dp[idx];
    ll ret=0;
    if(idx==0||idx==n-1)
    {
        if(!idx)
        {
            if(one)ret=max(ret,fn(idx+2,one)+coin[idx]);
            else ret=max(ret,fn(idx+1,one));
        }
        else
        {
            if(!one)ret=max(ret,fn(idx+2,one)+coin[idx]);
            else ret=max(ret,fn(idx+1,one));
        }
    }
    else{
        ret=max(ret,fn(idx+2,one)+coin[idx]);
        ret=max(ret,fn(idx+1,one));
    }
    return dp[idx]=ret;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,m;
    in(n);
    for(i=0;i<n;i++)in(coin[i]);
    ms(dp,-1);
    l=fn(0,true);
    ms(dp,-1);
    l=max(l,fn(0,false));
    printf("Case %d: ",cas++);
    cout<<l;endl;
    }
}
