#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)

using namespace std;


inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}

const int N = 505;
int a[N][N],b[N][N],c[N][N],d[N][N],n;

int main(){
	scanf("%d",&n);
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	rep(i,1,n) rep(j,1,n) b[i][j]=read();
	rep(i,1,n) rep(j,1,n) c[i][j]=read();
	rep(i,1,n) rep(j,1,n) rep(k,1,n) d[i][j]+=a[i][k]*b[k][j];
	rep(i,1,n) rep(j,1,n) if(d[i][j]!=c[i][j]) {puts("No"); exit(0);}
	puts("Yes");
}
