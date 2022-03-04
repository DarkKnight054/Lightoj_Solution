#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,t,k,l,m;
    scanf("%d",&t);
    getchar();
    for(i=1;i<=t;i++)
    {
        char s[105],p[105];
        l=1;
        gets(s);
        gets(p);
        int arr[27],ara[27],len1,len2;
         memset(arr,0,sizeof(arr));
         memset(ara,0,sizeof(ara));
        len1=strlen(s);
        len2=strlen(p);
         for(j=0;j<len1;j++)
         {
             if(s[j]>='A'&&s[j]<='Z'){arr[s[j]-'A']++;}
             else if(s[j]<='z'&&s[j]>='a'){arr[s[j]-'a']++;}
         }
        for(j=0;j<len2;j++)
         {
             if(p[j]>='A'&&p[j]<='Z'){ara[p[j]-'A']++;}
             else if(p[j]<='z'&&p[j]>='a'){ara[p[j]-'a']++;}
         }
        for(j=0;j<26;j++)
         if(ara[j]!=arr[j]){l=0;break;}
//         printf("%d %d\n",arr[j],ara[j]);}
        if(l)printf("Case %d: Yes\n",i);
        else printf("Case %d: No\n",i);
    }
    return 0;
}
