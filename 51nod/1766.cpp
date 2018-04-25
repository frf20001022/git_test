#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
#define ls t[x<<1]
#define rs t[x<<1|1]
#define fi first
#define se second

using namespace std;

inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;;int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}

#define ez(i,x) for(register int i=h[x];i;i=e[i].next)
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int N=100050;
const int M=25;
struct edge{int to,next,val;}e[N<<2];
int n,m,cnt,lg[M],f[N<<1][M],dep[N],val[N],pos[N],q[N<<1],tot,vis[N];
int h[N];
inline void add(int u,int v,int w){
	e[++cnt]=(edge){v,h[u],w};h[u]=cnt;
	e[++cnt]=(edge){u,h[v],w};h[v]=cnt;
}
void dfs(int x)
{
    if(vis[x]) return ;
    vis[x]=1;
    q[tot++]=x;
    pos[x]=tot-1;
    for(int i=h[x];i;i=e[i].next)
    {
        if(!vis[e[i].to ]) {
            dep[e[i].to]=dep[x]+e[i].val;
            dfs(e[i].to);
            q[tot++]=x;
        }
    }
}
void RMQ()
{
    for(int i=0;i<tot;i++) f[i][0]=q[i];
	rep(i,1,n) lg[i]=lg[i>>1]+1;
    for(int j=1;(1<<j)<=tot;j++)
    {
        for(int i=0;i+(1<<j)-1<tot;i++)
        {
            if(dep[f[i][j-1]]<dep[f[i+(1<<(j-1))][j-1]]) f[i][j]=f[i][j-1];
            else f[i][j]=f[i+(1<<(j-1))][j-1];
        }
    }
}
/*
inline void dfs(int x){
	vis[x]=1;
	q[++tot]=x;pos[x]=tot;
	ez(i,x){int v=e[i].to;if(!vis[e[i].to]) dep[v]=dep[x]+e[i].val,dfs(v),q[++tot]=x;}
}
void RMQ(){
	rep(i,1,tot) f[i][0]=q[i],lg[i]=lg[i>>1]+1; 
	for(int j=1;(1<<j) <=tot;j++) 
		for(int i=0;i+(1<<j) -1<tot;i++)
			if(dep[f[i][j]]<dep[f[i+(1<<(j-1))][j-1]]) f[i][j]=f[i][j-1];
			else f[i][j]=f[i+(1<<(j-1))][j-1];
}


inline int lca(int u,int v){
	if(pos[v]>pos[u]) swap(u,v);
	int l=lg[pos[u]-pos[v]+1];
	if(dep[f[pos[u]][l]]<dep[f[pos[v]-(1<<l)+1][l]])
	return f[pos[u]][l];
	return f[pos[v]-(1<<l)+1][l];
}
*/
inline int lca(int u,int v){
	if(pos[v]<pos[u]) swap(u,v);
        int k=lg[pos[v]-pos[u]+1];
        if(dep[f[pos[u]][k]]<dep[f[pos[v]-(1<<k)+1][k]])
        return f[pos[u]][k];
        else return f[pos[v]-(1<<k)+1][k];
}
inline int dis(int x,int y){return 1ll*dep[x]+dep[y]-2*dep[lca(x,y)];}
inline int dis(pii x) {return dis(x.fi,x.se);}
struct seg{
#define mid ((l+r)>>1)
#define mp make_pair
#define lc (x<<1)
#define rc (x<<1|1)
	pii g[N<<2];int d[N<<2];
	pii pushup(pii u,pii v,int d1=0,int d2=0,int x=0){
		if(!d1&&!d2) d1=dis(u),d2=dis(v);
		pii res=d1>d2?u:v;int dd=max(d1,d2);
		if(dis(u.fi,v.fi)>dd) res=mp(u.fi,v.fi),dd=dis(res);
		if(dis(u.fi,v.se)>dd) res=mp(u.fi,v.se),dd=dis(res);
		if(dis(u.se,v.fi)>dd) res=mp(u.se,v.fi),dd=dis(res);
		if(dis(u.se,v.se)>dd) res=mp(u.se,v.se),dd=dis(res);
		if(x) d[x]=dd;return res;
	}
	void build(int x,int l,int r){
		if(l==r) {g[x]=mp(l,l),d[x]=0;return ;}
		build(x<<1,l,mid);build(x<<1|1,mid+1,r);
		g[x]=pushup(g[lc],g[rc],d[lc],d[rc],x);
	}
	pii Query(int x,int l,int r,int L,int R){
		if(L<=l&&r<=R) return g[x];
		pii res= mp(L,L);
		if(L<=mid) res=Query(lc,l,mid,L,R);
		else res=pushup(res,Query(rc,mid+1,r,L,R));
		return res;
	}

	pii Merge(pii u,pii v){
		pii res=mp(u.fi,v.fi);int d=dis(res);
		if(dis(u.fi,v.se)>d) res=mp(u.fi,v.se),d=dis(res);
		if(dis(u.se,v.fi)>d) res=mp(u.se,v.fi),d=dis(res);
		if(dis(u.se,v.se)>d) res=mp(u.se,v.se),d=dis(res);
		return res;
	}
	int Query(int a,int b,int c,int d){
		pii r1=Query(1,1,n,a,b),r2=Query(1,1,n,c,d),r3=Merge(r1,r2);
		return dis(r3);
	}
}seg;

int main(){
	n=read();memset(dep,0x3f,sizeof(dep));
	int u,v,w;
	rep(i,1,n-1) u=read(),v=read(),w=read(),add(u,v,w);
	dfs(1);RMQ();seg.build(1,1,n);
	int kkk=read(),a,b,c,d;
	rep(i,1,kkk)a=read(),b=read(),c=read(),d=read(),printf("%d\n",seg.Query(a,b,c,d));
}





