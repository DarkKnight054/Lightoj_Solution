#include <bits/stdc++.h>
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
#define INF 1e8
#define SZ(_a) (int)_a.size()
#define dou(x) cout<<fixed<<setprecision(6)<<x
bool chq[26][26][26];
int level[26][26][26];
int dx[]={1,0,0,-1,0,0};
int dy[]={0,1,0,0,-1,0};
int dz[]={0,0,1,0,0,-1};
bool visit[26][26][26];
bool valid(int x,int y,int w)
{
    if(chq[x][y][w])return false;
    else return true;
}
bool bfs(string start,string stop)
{
    int i,j,k;
    char a,b,c;
    queue<string>q;
    if(valid(start[0]-'a',start[1]-'a',start[2]-'a'))q.push(start);
    visit[start[0]-'a'][start[1]-'a'][start[2]-'a']=true;
    level[start[0]-'a'][start[1]-'a'][start[2]-'a']=0;
    while(!q.empty())
    {
        string s=q.front();
        q.pop();
        if(s==stop)return true;
        for(i=0;i<6;i++)
            {
                a=s[0]+dx[i];b=s[1]+dy[i];c=s[2]+dz[i];
                if(a<'a')a='z';
                else if(a>'z')a='a';
                 if(b<'a')b='z';
                else if(b>'z')b='a';
                 if(c<'a')c='z';
                else if(c>'z')c='a';
                level[a-'a'][b-'a'][c-'a']=min(level[a-'a'][b-'a'][c-'a'],level[s[0]-'a'][s[1]-'a'][s[2]-'a']+abs(dx[i])+abs(dy[i])+abs(dz[i]));
                if(!visit[a-'a'][b-'a'][c-'a']&&valid(a-'a',b-'a',c-'a'))
                {
                    string st;
                    st.pb(a);st.pb(b);st.pb(c);
//                    cout<<st;endl;
                    visit[a-'a'][b-'a'][c-'a']=true;
                    q.push(st);
                    if(st==stop)return true;
                }
            }
    }
    return false;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m;
    string strt,stp;
    cin>>strt>>stp;
    in(n);
    ms(chq,false);
    ms(visit,false);
    for(i=0;i<26;i++)
        for(j=0;j<26;j++)
        for(k=0;k<26;k++)level[i][j][k]=INF;
    for(i=0;i<n;i++)
    {
        string a,b,c;
        cin>>a>>b>>c;
        for(j=0;j<SZ(a);j++)
            for(k=0;k<SZ(b);k++)
                for(l=0;l<SZ(c);l++)chq[a[j]-'a'][b[k]-'a'][c[l]-'a']=true;
    }
    bool ok=bfs(strt,stp);
    printf("Case %d: ",cas++);
    if(ok)cout<<level[stp[0]-'a'][stp[1]-'a'][stp[2]-'a']<<"\n";
    else puts("-1");
    }
    return 0;
}
