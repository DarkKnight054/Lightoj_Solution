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
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int n,i,j,k=0,l,m,o,p;
        in(n);
        vector<int>omar,rony,a;
        for(i=0;i<n;i++)
        {
            in(j);
            rony.pb(j);
        }
        for(i=0;i<n;i++)
        {
            in(j);
            omar.pb(j);
        }
        sort(omar.begin(),omar.end());
        sort(rony.begin(),rony.end());
        for(i=0;i<n;i++)
        {
            auto it=lower_bound(rony.begin(),rony.end(),omar[i]);
            if(it==rony.end())continue;
            l=*it;
            if(omar[i]==l)
            {
                auto it1=upper_bound(rony.begin(),rony.end(),omar[i]);
                if(it1==rony.end()){k++;
                rony.erase(it);continue;}
                auto it2=upper_bound(omar.begin(),omar.end(),omar[i]);
                if(it2==omar.end()){k+=2;rony.erase(it1);continue;}
                if(*it2>=*it1)
                {
                    k+=2;
                    rony.erase(it1);
                }
                else
                {
                    k++;
                    a.pb(omar[i]);
                    rony.erase(it);
                }
            }
            else
            {
                k+=2;
                rony.erase(it);
            }
//            CHECK(k);
        }
        j=SZ(a);
        for(i=0;i<j;i++)
        {
            auto it3=upper_bound(rony.begin(),rony.end(),a[i]);
            if(it3==rony.end())break;
            k++;
            rony.erase(it3);
        }
        printf("Case %d: ",cas++);
        out(k);endl;
    }
    return 0;
}
