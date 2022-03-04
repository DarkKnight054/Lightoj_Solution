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
ll dp[105][105];
string s;
ll fn(ll left,ll right)
{
    if(left>=right)return 0;
    if(dp[left][right]!=-1)return dp[left][right];
    ll ret=INT_MAX;
    if(s[left]==s[right])ret=0+fn(left+1,right-1);
    else
    {
        ret=min(ret,1+fn(left+1,right));
        ret=min(ret,1+fn(left,right-1));
    }
    return dp[left][right]=ret;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
         cin>>s;
    ms(dp,-1);
    printf("Case %d: ",cas++);
    cout<<fn(0,s.size()-1);endl;
    s.clear();
    }
    return 0;
}
