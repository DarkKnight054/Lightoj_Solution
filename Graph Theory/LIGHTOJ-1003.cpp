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
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define MAX 10005
vector<ll>adj[MAX];
ll visit[MAX],cycle=0;
void toposort(ll node)
{
    if(visit[node]==2||cycle)
        return ;
    if(visit[node])
    {
        cycle=1;
        return ;
    }
    visit[node]++;
    for(ll i=0; i<adj[node].size(); i++)
        toposort(adj[node][i]);
    visit[node]=2;
}
void clr(ll n)
{
    for(ll i=1; i<n; i++)
        adj[i].clear();
}
int main()
{
    ll test,cas=1LL;
    in(test);
    while(test--)
    {
        ll i,j,k,l,n,m;
        in(n);
        k=1LL;
        map<string,ll>omar;
        for(i=0; i<n; i++)
        {
            string x,y;
            cin>>x>>y;
            if(omar[x]==0)
                omar[x]=k++;
            if(omar[y]==0)
                omar[y]=k++;
            adj[omar[x]].pb(omar[y]);
        }
        cycle=0;
        ms(visit,0);
        for(i=1; i<k; i++)
            toposort(i);
        printf("Case %lld: ",cas++);
        if(!cycle)
            puts("Yes");
        else
            puts("No");
        clr(k);
    }
}
