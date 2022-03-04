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
int r,c;
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
char adj[505][505];
int ans[505][505];
bool visit[505][505];
bool valid(int a,int b)
{
    if(a>=1&&b>=1&&a<=r&&b<=c&&adj[a][b]!='#')return true;
    else return false;
}
void bfs(int x,int y)
{
    int ans1=0,i;
    queue< pii >q,q1;
    visit[x][y]=true;
    q.push({x,y});
    q1.push({x,y});
    if(adj[x][y]=='C')ans1++;
    while(!q.empty())
    {
        pii cur=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            x=cur.X+dr[i],y=cur.Y+dc[i];
            if(!visit[x][y]&&valid(x,y))
            {
                q.push({x,y});
                visit[x][y]=true;
                visit[x][y]=true;
                q1.push({x,y});
                if(adj[x][y]=='C')ans1++;
            }
        }
    }
    while(!q1.empty())
    {
        pii cur=q1.front();
        q1.pop();
        x=cur.X,y=cur.Y;
        ans[x][y]=ans1;
    }
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,q,x,y;
    in(r);in(c);in(q);
    ms(visit,false);
    ms(ans,0);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            cin>>adj[i][j];
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            if(adj[i][j]!='#'&&!ans[i][j])bfs(i,j);
    printf("Case %d:\n",cas++);
    for(i=0;i<q;i++)
    {
        in(x);in(y);
        out(ans[x][y]);endl;
    }
    }
    return 0;
}
