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
#define MAX 100005
#define INF 1000000000
#define MOD 1000000007
#define print(cs) printf("Case %lld: ",cs)
#define Yesno(ok) if(ok)puts("YES");else puts("NO")
#define yesno(ok) if(ok)puts("Yes");else puts("No")
ll lcm(ll a,ll b){return ((a*b)/__gcd(a,b));}
ll dx[]={1,1,2,2,-1,-1,-2,-2};
ll dy[]={2,-2,1,-1,2,-2,1,-1};
struct block{
    ll x,y,jump;
};
bool visit[12][12][12];
ll cnt[12][12][12],level[12][12],n,m;
void init()
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            for(ll k=0;k<10;k++)
            {
                visit[i][j][k]=false;
                cnt[i][j][k]=INF;
            }
        }
    }
}
void bfs(ll x,ll y,ll k)
{
    queue<block>pq;
    pq.push({x,y,k});
    cnt[x][y][k]=1;
    visit[x][y][k]=true;
    while(!pq.empty())
    {
        block pp=pq.front();
        pq.pop();
        for(ll i=0;i<8;i++)
        {
            ll lofo=0;
            ll xx=pp.x+dx[i],yy=pp.y+dy[i],kk=(pp.jump==0?k-1:pp.jump-1);
            if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
            {
//                if(x==4&&y==1)cout<<xx<<" valid "<<yy<<" "<<pp.x<<" "<<pp.y<<" JUMP "<<kk<<" "<<pp.jump<<'\n';
                if(pp.jump==0)lofo=1;
                cnt[xx][yy][kk]=min(cnt[xx][yy][kk],cnt[pp.x][pp.y][pp.jump]+lofo);
//                if(x==4&&y==1)cout<<"RESULT: "<<cnt[xx][yy][kk]<<'\n';
                if(!visit[xx][yy][kk])
                {
                    visit[xx][yy][kk]=true;
                    pq.push({xx,yy,kk});
                }
            }
        }
    }
    cnt[x][y][k]=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            if(level[i][j]==-1)continue;
            ll lofo=INF;
            for(ll lo=0;lo<10;lo++)lofo=min(lofo,cnt[i][j][lo]);
            if(lofo==INF)level[i][j]=-1;
            else level[i][j]+=lofo;
//            if(i==6&&j==4)cout<<level[i][j]<<" "<<lofo<<'\n';
        }
    }
}
int main()
{
    ll test,cas=1;
    in(test);
    while(test--)
    {
        ll i,j,k,l,r;
        in(n);in(m);
        char ss[n+5][m+5];
        for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin>>ss[i][j];
        ms(level,0);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(ss[i][j]!='.')
                {
                    init();
                    bfs(i,j,(ll)(ss[i][j]-'0'));
                }
            }
        }
        ll ans=INF;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(level[i][j]!=-1)ans=min(ans,level[i][j]);
            }
        }
        print(cas++);
        if(ans==INF)puts("-1");
        else cout<<ans<<'\n';
    }
}
