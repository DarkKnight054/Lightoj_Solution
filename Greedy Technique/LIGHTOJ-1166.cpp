#include<bits/stdc++.h>
#define pb push_back
#define vec(x,y) vector<x,y>
#define mp(x,y) map<x,y>
#define itr(x,y) vector<x,y>::iterator
#define mpr(x,y) map<x,y>::iterator
#define ppb pop()
#define str string::iterator
#define ll long long
#define Lin(x) scanf("%lld",&x)
#define Lout(x) printf("%lld",x)
#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define endl printf("\n")
using namespace std;
int main()
{
   int t,k;
   in(t);
    for(k=1;k<=t;k++)
    {
         int n,i,j,swp=0;
    in(n);
    int arr[n];
    for(i=0;i<n;i++)in(arr[i]);
    for(i=0;i<n;i++)
   while(arr[i]!=i+1)
   {
       swap(arr[i],arr[arr[i]-1]);
       swp++;
   }
    printf("Case %d: %d\n",k,swp);
    }
    return 0;
}
