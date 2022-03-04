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
bool visit[20005];
int color[20005];
int vampire=0,lykans=0;
int bfs(int sorce,vector<int>adj[20005])
{
    int ans=0,i;
    queue<int>q;
    visit[sorce]=true;
    q.pp(sorce);
    color[sorce]=RED;
    vampire++;
    while(!q.empty())
    {
        sorce=q.front();
        if(color[sorce]==0)color[sorce]=RED,vampire++;
        q.po();
        for(i=0;i<adj[sorce].size();i++)
        {
            if(!visit[adj[sorce][i]])
            {
//                cout<<"ar koto "<<adj[sorce][i];endl;
                if(color[sorce]==RED){color[adj[sorce][i]]=BLUE;
                lykans++;}
                else if(color[sorce]==BLUE){color[adj[sorce][i]]=RED;
                vampire++;}
//                cout<<"FINAL "<<sorce<<" "<<color[sorce]<<" "<<adj[sorce][i]<<" "<<color[adj[sorce][i]];endl;
//                cout<<vampire<<" "<<lykans;endl;
                q.pp(adj[sorce][i]);
                visit[adj[sorce][i]]=true;
            }
        }
    }
    return max(vampire,lykans);
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
    int u,v,n,i,j,k,l;
    int ans=0;
    vector<int>adj[20005],track;
    ms(visit,false);
    ms(color,0);
    in(n);
    for(i=0;i<n;i++)
    {
        in(u);in(v);
        adj[u].pb(v);
        adj[v].pb(u);
        track.pb(u);
        track.pb(v);
    }
    l=track.size();
    for(i=0;i<l;i++)
    {
        if(!visit[track[i]]){vampire=0,lykans=0;ans+=bfs(track[i],adj);}
    }
    printf("Case %d: ",cas++);
    cout<<ans;endl;
    }
    return 0;
}
