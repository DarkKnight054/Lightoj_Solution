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
bool visit[505][505];
int level[505][505];
bool valid(int a,int b)
{
    if(a>=1&&b>=1&&a<=r&&b<=c&&adj[a][b]!='#'&&adj[a][b]!='m')return true;
    else return false;
}
int bfs(int x,int y,int hx,int hy)
{
    queue< pii >q;
    q.push({x,y});
    int i;
    visit[x][y]=true;
    while(!q.empty())
    {
        pii cur=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            x=cur.X+dr[i],y=cur.Y+dc[i];
            if(!visit[x][y]&&valid(x,y))
            {
                visit[x][y]=true;
                q.push({x,y});
                level[x][y]=level[cur.X][cur.Y]+1;
                if(hx==x&&hy==y) return level[x][y];
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
    int i,j,k,l=0,x,y,ax,ay,bx,by,cx,cy,hx,hy;
    in(r);in(c);
    ms(visit,false);
    ms(level,0);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            {
                cin>>adj[i][j];
                if(adj[i][j]=='a')ax=i,ay=j;
                else if(adj[i][j]=='b')bx=i,by=j;
                else if(adj[i][j]=='c')cx=i,cy=j;
                else if(adj[i][j]=='h')hx=i,hy=j;
            }
    l=bfs(ax,ay,hx,hy);
//    cout<<"Fast "<<l;endl;
    ms(visit,false);
    ms(level,0);
    k=bfs(bx,by,hx,hy);
    l=max(l,k);
//    cout<<"Second "<<k;endl;
    ms(visit,false);
    ms(level,0);
    k=bfs(cx,cy,hx,hy);
    l=max(l,k);
//    cout<<"Third "<<k;endl;
    printf("Case %d: ",cas++);
    out(l);endl;
    }
    return 0;
}
