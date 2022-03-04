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
#define MAX 100005
#define MOD 1000000007
#define INF 1e18
#define dou(x) cout<<fixed<<setprecision(6)<<x
int arr[MAX];
bool chq(int mid,int n)
{
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        k=arr[i+1]-arr[i];
        if(k>mid)return false;
        else if(k==mid)mid--;
    }
    return true;
}
int main()
{
   int test,cas=1;
   in(test);
   while(test--)
   {
        int i,j,k,l,n,lo,hi,mid,ans;
    in(n);
    for(i=1;i<=n;i++)
        in(arr[i]);
    lo=0,hi=arr[n];
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(chq(mid,n))
        {
            ans=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    printf("Case %d: ",cas++);
    out(ans);endl;
   }
    return 0;
}
