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
bool visit[30005];
int ans[30005],milbe=0;
int bfs(int sorce,vector< pii >adj[30005])
{
    int si,i,ret;
    queue<int>q;
    q.push(sorce);
    visit[sorce]=true;
    while(!q.empty())
    {
        sorce=q.front();
        q.pop();
        si=SZ(adj[sorce]);
        for(i=0;i<si;i++)
        {
            pii cur=adj[sorce][i];
            if(!visit[cur.X])
            {
                visit[cur.X]=true;
                q.push(cur.X);
                ans[cur.X]=ans[sorce]+cur.Y;
                if(milbe<ans[cur.X])
                {
                    milbe=ans[cur.X];
                    ret=cur.X;
                }
            }
        }
    }
    return ret;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,u,v,w;
    in(n);
    ms(visit,false);
    vector< pii >adj[30005];
    for(i=0;i<n-1;i++)
    {
        in(u);in(v);in(w);
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    milbe=0;
    ms(ans,0);
    u=bfs(0,adj);
    ms(visit,false);
    ms(ans,0);
    milbe=0;
    bfs(u,adj);
    printf("Case %d: ",cas++);
    out(milbe);endl;
    }
    return 0;
}
