#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
#define ez(i,x) for(register int i=h[x];i;i=e[i].next)
#define Ez(i,x) for(register int i=H[x];i;i=e[i].next)
#define lowbit(x) (x&(-x))
using namespace std;

const int N= 1e5+100;
struct edge{int to,next;}e[N<<2];
long long ans;
int n,cnt,tot,fa[N],Fa[N],h[N],H[N],pos[N],l[N],r[N],t[N];
inline void add(int u,int v){e[++cnt]=(edge){v,h[u]};h[u]=cnt;}
inline void ADD(int u,int v){e[++cnt]=(edge){v,H[u]};H[u]=cnt;}
inline void Add(int pos,int v){for(;pos<=n;pos+=lowbit(pos)) t[pos]+=v;}
inline int sum(int x){int res=0;for(;x;x-=lowbit(x))res+=t[x];return res;}
inline void dfs(int x){l[x]=++tot;ez(i,x) dfs(e[i].to);r[x]=tot;}
inline void dfs1(int x){
	Add(l[x],1);
	int now=sum(r[x])-sum(l[x]);
	Ez(i,x)dfs1(e[i].to);
	long long tmp=sum(r[x])-sum(l[x]);tmp-=now;
	ans+=tmp*(tmp-1)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;int u,v;
	rep(i,1,n-1) cin>>u>>v,fa[v]=u,add(u,v);
	rep(i,1,n-1) cin>>u>>v,Fa[v]=u,ADD(u,v);
	//cerr<<"complete"<<endl;
	int r1,r2;
	rep(i,1,n) if(!fa[i]) r1=i;
	rep(i,1,n) if(!Fa[i]) r2=i;
	//cerr<<r1<<" "<<r2<<endl;
	dfs(r1);dfs1(r2);
	cout<<ans<<endl;
}

