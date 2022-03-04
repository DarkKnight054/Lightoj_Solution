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
ll dp[105][105][105];
vector<ll>coin;
ll k;
ll fn(ll par,ll idx,ll n,ll i,ll cnt,ll w)
{
    if(i==n)return 0;
    if(dp[par][i][cnt]!=-1)return dp[par][i][cnt];
    if(cnt&&coin[i]-idx<=w)return (ll)1+fn(par,idx,n,i+1,cnt,w);
    ll sum,cum;
    if(cnt<k)
    {
//        cout<<i<<" 1st\n";
        sum=1+fn(i,coin[i],n,i+1,cnt+1,w);
    }
    else sum=0;
//    cout<<i<<" 2nd "<<sum;endl;
    cum=fn(par,idx,n,i+1,cnt,w);
//    cout<<i<<" 3rd "<<cum;endl;
    return dp[par][i][cnt]=max(sum,cum);
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,l,n,m,w;
    in(n);
    in(w);
    in(k);
    ms(dp,-1);
    for(i=0;i<n;i++)
    {
        in(j);in(l);
        coin.pb(l);
    }
    sort(coin.begin(),coin.end());
    printf("Case %d: ",cas++);
    cout<<fn(0,0,n,0,0,w);
    endl;
    coin.clear();
    }
    return 0;
}
