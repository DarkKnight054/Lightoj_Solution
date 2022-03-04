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
ll coin[105];
ll dp[10005];
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
    ms(dp,0);
    dp[0]=1;
    ll i,j,k,l,n,m=MAX;
    in(n);in(make);
    for(i=0;i<n;i++)
    {
        in(coin[i]);
        m=min(m,coin[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=1;j<=make;j++)
        {
            k=j%coin[i];
            if(j-coin[i]>=0&&dp[j-coin[i]])dp[j]+=dp[j-coin[i]],dp[j]%=MAX;
        }
    }
    printf("Case %lld: ",cas++);
    cout<<dp[make];endl;
    }
    return 0;
}
