#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)
#define ez(i,x) for(register int i=h[x];i;i=e[i].next)
#define EZ(i,x) for(register int i=H[x];i;i=e[i].next)
using namespace std;
const int N=1e5+10,mod=1e9+7;
struct edge{int to,next;}e[N<<2];
int n,m,cnt,h[N],H[N],b[N],sz[N],w[N],v[N],sum,g[1<<20],leaf[N],in[N];
double f[1<<20];
inline void add(int u,int v){e[++cnt]=(edge){v,h[u]};h[u]=cnt;}
inline void Add(int u,int v){e[++cnt]=(edge){v,H[u]};H[u]=cnt;}
inline void dfs(int x,int last,int fa){
	sum++;
	if(in[x]!=2){
		b[++cnt]=x,w[cnt]=sum,sum=0;
		if(fa!=x) Add(fa,x),fa=x;
	}
	ez(i,x) if(e[i].to!=last) dfs(e[i].to,x,fa);
}
int main(){
	int x,y,tot;
	scanf("%d",&n);
	rep(i,1,n-1) scanf("%d%d",&x,&y),add(x,y),add(y,x),in[x]++,in[y]++;
	in[1]=-1;dfs(1,1,1);
	rep(i,2,n) if(in[i]==1) leaf[++m]=i,sz[i]=1;
	dow(i,cnt,1)EZ(j,b[i]) sz[b[i]]+=sz[e[j].to] ;
	tot=(1<<m)-1;
	f[0]=g[0]=1;
	rep(i,0,tot){
		rep(j,1,cnt) v[b[j]]=0;
		rep(j,1,m) if(i&(1<<(j-1))) v[leaf[j]]=1;
		int id=1;
		dow(j,cnt,1){
			EZ(k,b[j]) v[b[j]]+=v[e[k].to];
			if(v[b[j]]==sz[b[j]]) id+=w[j];
		}
		double t=f[i]*id;
		rep(j,1,m)
			if(!(i&(1<<(j-1)))&&t>f[1<<(j-1)|i])
				f[1<<(j-1)|i]=t,g[1<<(j-1)|i]=1ll*id*g[i]%mod;
	}
	cout<<g[tot]<<endl;
}
