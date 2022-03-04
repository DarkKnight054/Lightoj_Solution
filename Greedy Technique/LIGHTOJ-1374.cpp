#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define pp push
#define po pop
#define ms(a,b) memset(a, b, sizeof(a))
#define in(x) scanf("%d",&x)
#define Lin(x) scanf("%lld",&x)
#define out(x) printf("%d",x)
#define Lout(x) printf("%lld",x)
#define sps printf(" ")
#define X first
#define Y second
#define SZ(_a) (int)_a.size()
#define EPS 1e-9
#define PI acos(-1.0)
#define MAX 200005
#define MOD 1000000007
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b){return (a * (b / gcd(a, b)));}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int n,i,j,k,l;
    in(n);
    map<int,int>m;
    for(i=0;i<n;i++)
    {
        in(j);
        m[j]++;
    }
    bool ok;
    for(i=0;i<n;i++)
    {
        j=n-i-1;
        if(m.count(j)&&m[j]!=0)
        {
            m[j]--;
            ok=true;
        }
        else if(m.count(i)&&m[i]!=0)
         {
            m[i]--;
            ok=true;
        }
        else ok=false;
        if(!ok)break;
    }
    printf("Case %d: ",cas++);
    if(!ok)puts("no");
    else puts("yes");
    }
    return 0;
}
