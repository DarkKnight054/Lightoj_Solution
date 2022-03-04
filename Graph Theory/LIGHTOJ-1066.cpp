#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
#define endl printf("\n")
typedef pair<int,int> pii;
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
#define INF 1e9
#define dou(x) cout<<fixed<<setprecision(6)<<x
int dr[]= {0,0,1,-1};
int dc[]= {1,-1,0,0};
char food[15][15];
int level[15][15];
bool visit[15][15];
int valid(int x,int y,int n,char destination)
{
    if(x<0||x>=n||y<0||y>=n||food[x][y]=='#'||(food[x][y]>='A'&&food[x][y]<='Z'&&food[x][y]!=destination))return 0;
    else return 1;
}
int bfs(char stop,pii sorce,int n)
{
    int u,v,i,z;
    queue< pii >q;
    q.push(sorce);
    visit[sorce.X][sorce.Y]=true;
    while(!q.empty())
    {
        sorce=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            u=sorce.X+dc[i],v=sorce.Y+dr[i];
            z=valid(u,v,n,stop);
            if(z&&!visit[u][v])
            {
                visit[u][v]=true;
                level[u][v]=level[sorce.X][sorce.Y]+1;
                if(food[u][v]==stop)return level[u][v];
                q.push({u,v});
            }
        }
    }
    return -1;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m,ans=0;
    in(n);
    map<char, pii >track;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        cin>>food[i][j];
        if(food[i][j]>='A'&&food[i][j]<='Z')track[food[i][j]]={i,j};
    }
    j=SZ(track);
    printf("Case %d: ",cas++);
    for(i=0;i<j-1;i++)
    {
        ms(visit,false);
        ms(level,0);
        char strt='A'+i;
        char stp='A'+i+1;
        k=bfs(strt,track[stp],n);
        if(k==-1){puts("Impossible");ans=-1;break;}
        else
        {
            ans+=k;
            pii now=track[strt];
            food[now.X][now.Y]='.';
        }
    }
    if(ans!=-1){out(ans);endl;}
    }
    return 0;
}
