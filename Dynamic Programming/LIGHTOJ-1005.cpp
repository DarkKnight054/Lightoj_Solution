#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
int main()
{
    ll test,cas=1,k,i,j=1,l,n,m;
    in(test);
    while(test--)
    {
        cin>>n>>k;
        m=1;
        j=1;
    for(i=0;i<k;i++)
    {
        j*=(n-i)*(n-i);
        m*=(i+1);
        l=__gcd(j,m);
//        cout<<j<<" "<<m<<" "<<l;endl;
        j/=l;
        m/=l;
    }
    l=__gcd(j,m);
    j/=l;
    m/=l;
    printf("Case %d: ",cas++);
    cout<<j;endl;
    }
}
