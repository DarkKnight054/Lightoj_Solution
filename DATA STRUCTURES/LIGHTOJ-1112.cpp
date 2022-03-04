#include<bits/stdc++.h>
using namespace std;
int tree[100005],arr[100005];
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
void update(int idx,int val,int n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}
int main()
{
    int d,t;
    scanf("%d",&t);
    for(d=1;d<=t;d++)
    {
    memset(tree,0,sizeof(tree));
        int n,m;
    scanf("%d %d",&n,&m);
     printf("Case %d:\n",d);
    int i,j,k,l,v;
    for(i=1;i<=n;i++){
            scanf("%d",&j);
        arr[i]=j;
        update(i,j,n);
    }
    for(j=0;j<m;j++)
    {
            scanf("%d",&k);
            if(k==1)
            {
                scanf("%d",&l);
                printf("%d\n",arr[l+1]);
                update(l+1,-arr[l+1],n);
                arr[l+1]=0;
            }
            else if(k==2)
            {
                    scanf("%d %d",&l,&v);
                    update(l+1,v,n);
                    arr[l+1]+=v;
            }
            else if(k==3)
            {
                scanf("%d %d",&l,&v);
                printf("%d\n",query(v+1)-query(l));
            }
    }
    }
    return 0;
}
