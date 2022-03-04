#include <bits/stdc++.h>
using namespace std;
#define ll  long long
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
struct house{
ll red;
ll blue;
ll green;
};
ll n;
house arr[25];
ll dp[25][5];
ll fn(ll idx,ll color)
{
    if(idx==n)return 0;
    if(dp[idx][color]!=-1)return dp[idx][color];
    ll mn=INT_MAX;
    if(color!=1)mn=min(mn,fn(idx+1,1)+arr[idx].red);
    if(color!=2)mn=min(mn,fn(idx+1,2)+arr[idx].green);
    if(color!=3)mn=min(mn,fn(idx+1,3)+arr[idx].blue);
    return dp[idx][color]=mn;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,m;
    in(n);
    for(i=0;i<n;i++)
    {
        in(arr[i].red);
        in(arr[i].green);
        in(arr[i].blue);
    }
    ms(dp,-1);
    printf("Case %d: ",cas++);
    cout<<fn(0,0);endl;
    }
    return 0;
}
