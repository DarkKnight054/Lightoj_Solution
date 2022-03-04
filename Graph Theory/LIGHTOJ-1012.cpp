#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef pair<int,int> pii;
typedef vector <int> VI;
typedef vector<ll> VL;
typedef set<int> SI;
#define mp make_pair
#define pb push_back
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
#define INF 1e9
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define RED 10
#define BLUE -10
#define pp push
#define po pop
int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};
int r,c,adj[25][25];
bool visit[25][25];
bool valid(int a,int b)
{
    if(a>=1&&a<=r&&b>=1&&b<=c&&adj[a][b])return true;
    else return false;
}
int bfs(pii sorce)
{
    int ans=1,u,v,i;
    queue<pii>q;
    q.pp(sorce);
    visit[sorce.X][sorce.Y]=true;
    while(!q.empty())
    {
        sorce=q.front();
        q.po();
        u=sorce.X,v=sorce.Y;
        for(i=0;i<4;i++)
        {
            if(!visit[u+dr[i]][v+dc[i]]&&valid(u+dr[i],v+dc[i]))
            {
                q.pp({u+dr[i],v+dc[i]});
                visit[u+dr[i]][v+dc[i]]=true;
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        in(c);in(r);
    int i,j,k,l;
    char ch;
    memset(visit,false,sizeof(visit));
    pii sorce;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
    {
        cin>>ch;
        if(ch=='.')adj[i][j]=1;
        else if(ch!='@')adj[i][j]=0;
        else sorce={i,j};
    }
    printf("Case %d: ",cas++);
    cout<<bfs(sorce);endl;
    }
    return 0;
}
