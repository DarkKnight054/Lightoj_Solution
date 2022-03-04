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
using namespace std;
int main()
{

    int t,caseno=0;
    in(t);
    while(t--)
    {
        double a,b,c,angle,d,e,f;
    scanf("%lf : %lf",&a,&b);
    e=a/2;
    f=b/2;
    d=sqrt((e*e)+(f*f));
    angle=2*atan(f/e);
//    cout<<d<<" "<<angle;endl;
    c=d*angle;
//    cout<<c;dbg;
    d=(400.0/(2*c+2*a));
    printf("Case %d: %6lf %6lf\n",++caseno,a*d,b*d);
    }
    return 0;
}
