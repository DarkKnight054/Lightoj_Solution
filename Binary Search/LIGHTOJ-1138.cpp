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
#define all(v) v.begin(),v.end()
#define dis(it,it1) distance(it,it1)+1
#define MAX 100005
#define INF  9223372036854775807
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll fk(ll n)
{
    ll sum=0;
    while(n)
        sum+=n/5,n/=5;
    return sum;
}
int main()
{
    ll t,i;
    in(t);
    for(i=1;i<=t;i++)
    {
        ll q,lo,hi,mid,ans;
        in(q);
        lo=1,hi=10000000000*5;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(fk(mid)>=q)
            {
                ans=mid;
                hi=mid;
            }
            else lo=mid+1;
        }
        printf("Case %lld: ",i);
        if(fk(ans)!=q)printf("impossible\n");
        else {out(ans);endl;}
    }
    return 0;
}
