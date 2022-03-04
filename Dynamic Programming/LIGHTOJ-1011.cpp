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
int flip(int n,int pos){return n=n|(1<<pos);}
int flop(int n,int pos){return n=n&~(1<<pos);}
bool check(int n,int pos){return (bool)(n&(1<<pos));}
ll dp[20][(1<<17)+5];
ll mat[20][20];
ll n;
ll fn(ll idx,ll mask)
{
    if(mask==(1<<n)-1)return 0;
    if(dp[idx][mask]!=-1)return dp[idx][mask];
    ll i,j,ret,mn=0;
//    CHECK(idx);
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
//            cout<<" 1 "<<mat[idx][mask]<<" "<<mask<<"\n";
            ret=mat[idx][i]+fn(idx+1,flip(mask,i));
//            cout<<" 2 "<<ret<<" "<<mask<<"\n";
            mn=max(mn,ret);
        }
    }
    return dp[idx][mask]=mn;
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        in(n);
    ll i,j,k,l;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)in(mat[i][j]);
    ms(dp,-1);
    printf("Case %d: ",cas++);
    cout<<fn(0,0);endl;
    }
    return 0;
}
