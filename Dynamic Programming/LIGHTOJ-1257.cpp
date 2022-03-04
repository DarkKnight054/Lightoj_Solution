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
#define MAX 100005
#define MOD 1000000007
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b){return (a * (b / gcd(a, b)));}
vector< pii >adj[MAX];
int dog[MAX];
bool visit[MAX];
int level[MAX];
int milbe=0,ret;
void dfs(int v)
{
    visit[v]=true;
    int i=0,cur;
    for(i=0;i<adj[v].size();i++)
    {
        pii cur=adj[v][i];
        if(!visit[cur.X])
        {
            dog[cur.X]=dog[v]+cur.Y;
            level[cur.X]=level[v]+cur.Y;
            if(level[cur.X]>milbe)
            {
                milbe=level[cur.X];
                ret=cur.X;
            }
            dfs(cur.X);
        }
    }
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
    int i,j,k,l,n,u,v,d;
    in(n);
    for(i=0;i<n-1;i++)
    {
        in(u);in(v);in(d);
        u++,v++;
        adj[u].pb(mp(v,d));
        adj[v].pb(mp(u,d));
    }
    milbe=0;
    ms(dog,0);
    ms(visit,false);
    ms(level,0);
    dfs((int)1);
    k=ret;
    milbe=0;
    ms(dog,0);
    ms(visit,false);
    ms(level,0);
    dfs(k);
//    cout<<k;endl;
    l=ret;
//    for(i=1;i<=n;i++)
//        CHECK(level[i]);
//    cout<<ret;endl;
//    cout<<l;endl;
    int ans1[n+1],ans2[n+1];
    for(i=1;i<=n;i++)
        ans1[i]=dog[i];
    milbe=0;
    ms(dog,0);
    ms(visit,false);
    ms(level,0);
    dfs(l);
    for(i=1;i<=n;i++)
        ans2[i]=dog[i];
    printf("Case %d:\n",cas++);
//    cout<<k<<" "<<l;endl;
    for(i=1;i<=n;i++)
    {
        k=max(ans1[i],ans2[i]);
        cout<<k;endl;
    }
    for(i=1;i<=n;i++)
        adj[i].clear();
    }
    return 0;
}
