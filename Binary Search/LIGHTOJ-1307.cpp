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
#define MAX 2005
#define MOD 1000000007
#define INF 1e8
#define dou(x) cout<<fixed<<setprecision(6)<<x
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a % b));}
int lcm(int a, int b){return (a * (b / gcd(a, b)));}
int arr[MAX];
int solve(int sum,int index,int n)
{
    int lo=index+1,hi=n-1,mid,cnt=0;
    while(lo<=hi)
    {
//        CHECK(lo);
//        CHECK(hi);
        mid=lo+(hi-lo)/2;
        if(arr[mid]<sum)
        {
            cnt=max(cnt,mid);
            lo=mid+1;
        }
        else hi=mid-1;
    }
//    cout<<cnt<<" "<<index;endl;
    if(cnt==0)return 0;
    else return cnt-index;
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int i,j,k,l=0,n,m;
    in(n);
    for(i=0;i<n;i++)
        in(arr[i]);
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
                k=arr[i]+arr[j];
                l+=solve(k,j,n);
        }
    }
    printf("Case %d: ",cas++);
    out(l);endl;
    }
}
