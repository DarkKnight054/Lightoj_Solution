    #include <bits/stdc++.h>
    using namespace std;
    #define ll int
    #define dbg puts("It's Just Begining.Wait For The End!!!!!\n")
    #define CHECK(x) cout << (#x) << " is " << (x) <<"\n";
    #define endl printf("\n")
    typedef pair<ll,ll> pii;
    #define pb push_back
    #define ms(a,b) memset(a, b, sizeof(a))
    #define in(x) scanf("%d",&x)
    #define out(x) printf("%d",x)
    #define X first
    #define Y second
    #define sps printf(" ")
    #define dou(x) cout<<fixed<<setprecision(6)<<x
    #define all(v) v.begin(),v.end()
    #define dis(it,it1) distance(it,it1)+1
    #define MAX 100005
    #define MOD 1000000007
    #define print(cs) printf("Case %lld:\n",cs)
    int main()
    {
        ll test,cs=0;
        in(test);
        while(test--)
        {
            ll i,j,k,l,r,n,m;
            in(n);
            ll qu;
            in(qu);
            vector<ll>v;
            for(i=0;i<n;i++)
            {
                in(j);
                v.pb(j);
            }
            print(++cs);
            while(qu--)
            {
                char c;
                cin>>c;
                if(c=='c')
                {
                    in(k);
                    k--;
                    if(k>v.size()-1)puts("none");
                    else
                    {
                        out(v[k]);endl;
                        v.erase(v.begin()+k);
                    }
                }
                else
                {
                    in(k);
                    v.pb(k);
                }
            }
        }
    }
