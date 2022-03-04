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
#define MAX 1005
#define MOD 1000000007
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b){return (a * (b / gcd(a, b)));}
bool visit[MAX];
int cnt[MAX];
int ans;
void bfs(int sorce,vector<int>adj[MAX],int k)
{
    int i,cur;
    queue<int>q;
    q.push(sorce);
    visit[sorce]=true;
    cnt[sorce]++;
    if(cnt[sorce]==k)ans++;
    while(!q.empty())
    {
        sorce=q.front();
        q.pop();
        for(i=0;i<adj[sorce].size();i++)
        {
            cur=adj[sorce][i];
            if((!visit[cur]))
            {
                visit[cur]=true;
                cnt[cur]++;
                if(cnt[cur]==k)ans++;
                q.push(cur);
            }
        }
    }
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int n,m,k,i,j,l,o,p,u,v;
    vector<int>adj[MAX];
    in(k);in(n);in(m);
    vector<int>city;
    for(i=0;i<k;i++)
    {
        in(j);
        city.pb(j);
    }
    for(i=0;i<m;i++)
    {
        in(u);in(v);
        adj[u].pb(v);
    }
    ms(cnt,0);
    ans=0;
    for(i=0;i<k;i++)
    {
        ms(visit,false);
        bfs(city[i],adj,k);
    }
    printf("Case %d: ",cas++);
    out(ans);endl;
    }
    return 0;
}
