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
#define sps printf(" ");
#define X first
#define Y second
#define dou(x) cout<<fixed<<setprecision(6)<<x
#define MAX 2000005
ll z_array[MAX];
void z_algorithm(string pattern)
{
    ll left=0LL,right=0LL,k,k1;
    z_array[0]=0LL;
    for(k=1;k<pattern.size();k++)
    {
        if(k>right)
        {
            left=right=k;
            while(right<pattern.size()&&pattern[right]==pattern[right-left])right++;
            z_array[k]=right-left;
            right--;
        }
        else
        {
            k1=k-left;
            if(z_array[k1]<right-k+1)z_array[k]=z_array[k1];
            else
            {
                left=k;
                while(right<pattern.size()&&pattern[right]==pattern[right-left]){right++;}
                z_array[k]=right-left;
                right--;
            }
        }
    }
}
ll solve()
{
    ll i,j,k,l,n,m;
    string text,pattern,s;
    cin>>pattern;
    text=pattern;
    reverse(pattern.begin(),pattern.end());
    s+=pattern;
    s+="$";
    s+=text;
    z_algorithm(s);
    i=pattern.size();
    while(i<s.size()&&z_array[i]!=s.size()-i)++i;
    return i-1;
}
int main()
{
    ll test,cas=1LL;
    in(test);
    while(test--)
    {
        ll ans=solve();
        printf("Case %lld: ",cas++);
        out(ans);endl;
    }
}
