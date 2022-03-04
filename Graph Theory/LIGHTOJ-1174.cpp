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
    bool visit[105];
    int dis[105];
    int bfs(int sorce,vector<int>adj[105],int v)
    {
        int i,j,k,l;
        queue<int>q;
        q.push(sorce);
        visit[sorce]=true;
        while(!q.empty())
        {
            sorce=q.front();
            if(sorce==v)
                return dis[v];
            q.pop();
            l=adj[sorce].size();
            for(i=0;i<l;i++)
            {
                if(!visit[adj[sorce][i]])
                {
                    dis[adj[sorce][i]]=dis[sorce]+1;
                    q.push(adj[sorce][i]);
                    visit[adj[sorce][i]]=true;
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
        int i,j,ans=0,l,k,n,m,u,v;
        ms(visit,false);
        ms(dis,0);
        vector<int>adj[105];
        in(n);
        in(m);
        for(i=0;i<m;i++)
        {
            in(u);in(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        in(u);in(v);
        ans=bfs(u,adj,v);
        for(i=0;i<n;i++)
        {
            if(i!=u&&i!=v)
            {
                 ms(dis,0);
                 ms(visit,false);
                 k=bfs(u,adj,i);
                  ms(dis,0);
                  ms(visit,false);
                l=bfs(i,adj,v);
                ans=max(ans,k+l);
            }
        }
        printf("Case %d: ",cas++);
        out(ans);endl;
        }
        return 0;
    }
