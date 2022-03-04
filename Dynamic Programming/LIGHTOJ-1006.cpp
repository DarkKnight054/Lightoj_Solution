#include<bits/stdc++.h>
using namespace std;
long long int fibo[10000+33 ];
int a, b, c, d, e, f;
long long int fn( int n ) {
    if(fibo[n]!=-1)return fibo[n];
    if( n==0||n==1||n==2||n==3||n==4||n==5) return fibo[n];
    fibo[n]=(fn(n-1)%10000007+ fn(n-2)%10000007+ fn(n-3)%10000007 + fn(n-4)%10000007 + fn(n-5)%10000007 + fn(n-6)%10000007)%10000007;
    return fibo[n]%10000007;
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset(fibo,-1,sizeof fibo);
        fibo[0]=a%10000007;
        fibo[1]=b%10000007;
        fibo[2]=c%10000007;
        fibo[3]=d%10000007;
        fibo[4]=e%10000007;
        fibo[5]=f%10000007;
        printf("Case %d: %lld\n", ++caseno, fn(n));
    }
    return 0;
}
