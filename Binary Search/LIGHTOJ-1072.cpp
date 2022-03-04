#include<stdio.h>
#include<math.h>
#define pi 3.141592654
int main()
{
    int i,t;
    scanf("%d",&t);
    double r,R,n,ang;
   for(i=1;i<=t;i++)
   {
    scanf("%lf%lf",&R,&n);
    ang=pi/n;
    r=(sin(ang)*R)/(1+sin(ang));
    printf("Case %d: %lf\n",i,r);
   }
    return 0;
}
