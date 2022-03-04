#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        double a,b,c,d,ans;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    ans=sqrt((a*a*d)/(1+d));
    printf("Case %d: %lf\n",i,ans);
    }
    return 0;
}
