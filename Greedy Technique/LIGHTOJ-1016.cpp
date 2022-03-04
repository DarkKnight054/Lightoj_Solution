#include <bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
#define CHECK(x) cout << (#x) << " is " << (x) << endl;
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
#define MAX 100005
#define MOD 1000000007
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
bool cmp(pii a,pii b)
{
    return a.Y<b.Y;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m,u,v;
        in(n);in(m);
        vector< pii >intervals;
        for(i=0;i<n;i++)
        {
            in(u);in(v);
            intervals.pb({u,v});
        }
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int>q;
        q.push(intervals[0].Y);
        for(i=1;i<n;i++)
        {
            if(q.top()+m<intervals[i].Y)
                q.push(intervals[i].Y);
        }
        printf("Case %d: ",cas++);
        cout<<SZ(q);endl;
    }
    return 0;
}
