#include <bits/stdc++.h>
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
#define INF 1e9
#define dou(x) cout<<fixed<<setprecision(6)<<x
int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
int level[1005];
bool visit[1005];
void bfs(int a,int b)
{
    queue<int>q;
    q.push(a);
    level[a]=0;
    visit[a]=true;
    while(!q.empty())
    {
        int cur=q.front(),rec;
        q.pop();
        for(int i=0;i<168;i++)
        {
                if(cur<=prime[i])break;
                if(cur%prime[i]==0)rec=cur+prime[i];
                else continue;
                if(rec>b)continue;
                level[rec]=min(level[rec],level[cur]+1);
                if(!visit[rec])
                {
                    q.push(rec);
                    visit[rec]=true;
                }
        }
    }
}
int main()
{
    int test,cas=1;
    in(test);
    while(test--)
    {
        int a,b,i,j,k,l;
    in(a);in(b);
    for(i=1;i<1005;i++)level[i]=INF;
    ms(visit,false);
    if(b>a)bfs(a,b);
    level[a]=0;
    printf("Case %d: ",cas++);
    if(level[b]==INF)puts("-1");
    else cout<<level[b]<<"\n";
    }
    return 0;
}
