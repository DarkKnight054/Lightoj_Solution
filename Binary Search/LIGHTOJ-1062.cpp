#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg puts("Viva la vida")
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
#define INF 1<<32
#define dou(x) cout<<fixed<<setprecision(6)<<x
int main()
{
   int t,j;
   in(t);
   for(j=1;j<=t;j++)
   {
        double x,y,c,w,p,q,c1,lo=1,hi;
    cin>>x>>y>>c;
    hi=min(x,y);
    while(1)
    {
        w=(lo+hi)/2;
        p=sqrt(x*x-w*w);
        q=sqrt(y*y-w*w);
        c1=1/((1/p)+(1/q));
        if(fabs(c-c1)<EPS)break;
        else if(c1+EPS>c)lo=w;
        else hi=w;
    }
    printf("Case %d: ",j);
    cout<<fixed;
    cout<<setprecision(6)<<w;endl;
   }
    return 0;
}
