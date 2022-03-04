#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <bits/stdc++.h>
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
   int t,caseno=1;
   in(t);
   while(t--)
   {
        int i,j,m,k,l,n,q;
    in(n);in(q);
    VI a;
    for(i=0;i<n;i++)
    {
        in(k);
        a.pb(k);
    }
    sort(a.begin(),a.end());
    VI::iterator it,it1;
    printf("Case %d:\n",caseno++);
    for(i=0;i<q;i++)
    {
        in(l);in(m);
        it=lower_bound(a.begin(),a.end(),l);
        it1=lower_bound(a.begin(),a.end(),m);
        if(*it1!=m||it1==a.end())it1--;
//        cout<<*it<<" "<<*it1;endl;
        m=distance(it,it1)+1;
        cout<<m;endl;
    }
   }
}
