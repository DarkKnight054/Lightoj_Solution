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
ll mat[205][205];
ll dp[205][205];
ll n;
ll fn(ll left,ll right)
{
    if(left>=0&&left<2*n-1&&right>=0&&right<2*n-1)
    {
        if(dp[left][right]!=-1)return dp[left][right];
        ll ret=0;
        ret=max(ret,fn(left+1,right-1)+mat[left][right]);
        ret=max(ret,fn(left+1,right+1)+mat[left][right]);
        return dp[left][right]=ret;
    }
    else return 0;
}
int main()
{
   ll test,cas=1;
   in(test);
   while(test--)
   {
        ms(mat,0);
    ms(dp,-1);
    ll i,j,k,l,m;
    in(n);
    for(i=0,k=n-1;i<n;i++,k--)
    {
        l=i+1;
        for(j=k,m=0;j<2*n-1&&m<l;j+=2,m++)
        {
            in(mat[i][j]);
        }
    }
    for(l=n-1,k=1;i<2*n-1;i++,l--,k++)
    {
        for(j=k,m=0;j<2*n-1&&m<l;m++,j+=2){in(mat[i][j]);}
    }
    printf("Case %lld: ",cas++);
    cout<<fn(0,n-1);endl;
   }
   return 0;
}
