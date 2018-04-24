#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
using namespace std;
const int N= 105;
const int M= 50005;
const int mod=1e9+7;
long long f[N][N][N],g[N];
int mu[N],n,m,p[N],isp[N];
int u[N],v[N],w[N];
int main(){
	rep(i,2,100){
		if(!isp[i]) p[++p[0]]=i,mu[i]=1;
		rep(j,1,p[0]){
			int k=i*p[j];
			if(k>=100) break;
			isp[k]=1;
			if(i%p[j]){mu[k]=0;break;}
			else mu[k]=-mu[i];
		}
	}

	n=read(),m=read();
	rep(i,1,m){
		u[i]=read(),v[i]=read(),w[i]=read();
		for(register int j=1;j*j<=w[i];j++)if(c[i]%j==0){
			f[j][u[i]][v[i]]++,g[j]++;
			if(j*j!=w[i]) f[w[i]/j][u[i]][v[i]]++,g[w[i]/j]++;
	}
	rep(x,1,100)rep(k,1,n)rep(i,1,n)rep(j,1,n) (f[i][j]+=f[i][k]*f[k][j])%mod,(g[j]+=f[i][k]*f[k][j])%mod;
	long long ans=0;rep(x,1,100)(ans+=g[i]*mu[i])%mod;
	printf("%lld\n",ans);int T;
	cin>>T;
	while(T--){
		int id=read(),val=read();
		for(register int x=1;x*x<=w[id];x++)if(w[id]%x)==0;
			f[x][v[i]][v[i]]=f[x][u[i]][u[i]]=1;




