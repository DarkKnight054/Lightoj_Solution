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
#define MAX 400005
#define INF  9223372036854775807
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
int main()
{
    ll test=1LL,cas=0;
    cin>>test;
    while(test--)
    {
        ll i,j,k,l,n,m,r;
        in(n);
        ll arr[20];
        arr[0]=1LL;
        vector<ll>vv;
        for(i=1;i<20;i++)arr[i]=arr[i-1]*i;
        for(i=19;i>=0&&n;i--)
        {
            if(n>=arr[i])
            {
                vv.pb(i);
                n-=arr[i];
            }
        }
        print(++cas);
        if(n)puts("impossible");
        else
        {
            sort(all(vv));
            for(i=0;i<vv.size()-1;i++)cout<<vv[i]<<"!+";
            cout<<vv[vv.size()-1]<<"!";endl;
        }
    }
}
