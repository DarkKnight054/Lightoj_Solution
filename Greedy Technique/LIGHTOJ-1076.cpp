#include <bits/stdc++.h>
#include<cmath>
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
#define SZ(_a) (int)_a.size()
#define EPS 1e-9
#define PI acos(-1.0)
#define MAX 1005
#define MOD 1000000007
#define INF 1e8
#define dou(x) cout<<fixed<<setprecision(6)<<x
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b){return (a * (b / gcd(a, b)));}
int arr[MAX];
bool chq(int mid,int m,int n)
{
    int i,j=0,k,l;
    k=m;
    i=0;
    while(k&&i<n)
    {
        j+=arr[i];
        if(j>mid)
        {
            j=0;
            k--;
        }
        else i++;
    }
    if(i==n)return true;
    else return false;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l,n,m,lo=INF,hi=0,mid,ans;
        in(n);in(m);
        for(i=0;i<n;i++){in(arr[i]);
        lo=min(lo,arr[i]);
        hi+=arr[i];
        }
        while(lo<=hi)
        {
            mid=lo+(hi-lo)/2;
            if(chq(mid,m,n))
            {
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        printf("Case %d: ",cas++);
        out(ans);endl;
    }
    return 0;
}
