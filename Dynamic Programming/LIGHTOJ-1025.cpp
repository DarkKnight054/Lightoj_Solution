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
string s;
ll dp[65][65];

ll fn(ll i,ll j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;
//    if(i==j-1&&s[i]==s[j])return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    ll ret1= 0,ret3= 0,ret2= 0;

    if( s[i]==s[j] )
    {
        ret1=fn(i+1,j);
        ret2=fn(i,j-1);
        ret2++;
    }
    else
    {
        ret1=fn(i,j-1);
        ret2=fn(i+1,j);
        ret3=fn(i+1,j-1);
    }
    return dp[i][j]= ret1+ret2-ret3;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
    cin>>s;
    ll i,j,k,l,n,m;
    n=s.size()-1;
    ms(dp,-1);
    printf("Case %lld: ",cas++);
    cout<<fn(0,n);endl;
    s.clear();
    }
    return 0;
}
