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
vector<int> createtemparray(string pattern)
{
    int index=0,i=1;
    vector<int>lps(pattern.length());
    while(i<pattern.length())
    {
        if(pattern[index]==pattern[i])
            lps[i]=index+1,i++,index++;
        else
        {
            if(index!=0)index=lps[index-1];
            else lps[i]=index,i++;
        }
    }
    return lps;
}
void kmp(string text, string pattern)
{
    vector<int>lps=createtemparray(pattern);
    int i=0,j=0,n,cnt=0;
    while(i<=text.length())
    {
        if(text[i]==pattern[j])++i,++j;
        else
        {
            if(j!=0)j=lps[j-1];
            else ++i;
        }
        if(j==pattern.length())
        {
//            cout<<cnt<<" "<<i-pattern.length()+1;endl;
            cnt++;
//            k=0;
        }
    }
    out(cnt);endl;
}
int main()
{
    int i,j,k,l,n;
    in(n);
//    ll sum,cum,m;
  for(i=1;i<=n;i++)
  {
        string  text,pattern;
    cin>>text>>pattern;
    printf("Case %d: ",i);
    kmp(text,pattern);
  }
    return 0;
}
