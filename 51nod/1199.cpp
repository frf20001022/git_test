#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)
#define ez(i,x) for(register int i=h[x];i;i=e[i].nxt)
#define ls t[x<<1]
#define rs t[x<<1|1]
#define cur t[x]
#define PU(x) cur.sum=ls.sum+rs.sum;
#define PD push_down
#define RG register 
#define il inline 

using namespace std;

typedef long long ll;
const int N = 5e4+100;
int n,m,tot,pos[N],h[N],cnt,siz[N],fa[N],w[N],wel[N];
struct edge{int v,nxt;}e[N<<1];
struct node{int l,r,add;ll sum;}t[N<<2];

il int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar())) num=(num<<1)+(num<<3)+ch-'0';
	return num*f;
}

il void add(int u,int v){e[++cnt]=(edge){v,h[u]},h[u]=cnt;}
inline void push_down(int x){
	if( t[x].add ){
		ls.sum += 1ll * ( ls.r -  ls.l + 1 ) * cur.add , ls.add += t[x].add;
		rs.sum += 1ll * ( rs.r - rs.l + 1 ) * cur.add , rs.add += cur.add;
		cur.add=0;
	}
}

void build(int x,int l,int r){
	cur.l = l , cur.r = r;
	if( l == r )  {   cur.sum = w[l]; return ;}
	int mid = l + r >> 1;
	build( x<<1 , l , mid );
	build( x<<1|1 ,mid + 1 , r);
	PU(x);
}

void modify(int x,int l,int r,int val){
	if(r<t[x].l||l>t[x].r) return ;
	if(l<=t[x].l&&t[x].r<=r){
		cur.sum+=(cur.r-cur.l+1)*1ll*val;
		cur.add+=val;
		return ;
	}PD(x);
	modify(x<<1,l,r,val);modify(x<<1|1,l,r,val);
	PU(x);
}

ll Sum(int x,int l,int r){
	if(r<t[x].l||l>t[x].r) return 0 ;
	if(l<=t[x].l&&t[x].r<=r) return cur.sum;
	PD(x) ;
	return Sum(x<<1,l,r)+Sum(x<<1|1,l,r);
}

void dfs(int x){siz[x]=1;pos[x]=++tot;ez(i,x)dfs(e[i].v),siz[x]+=siz[e[i].v];}
char op[2];
long long x,y,z;
int main(){
	n=read(),m=read();
	rep(i,1,n-1) fa[i]=read(),wel[i]=read(),add(fa[i],i);
	dfs(0);rep(i,0,n-1) w[pos[i]]=wel[i];
//	rep(i,1,n) cerr<<w[i]<<endl;
	build(1,1,n);
	rep(i,1,m){
		scanf("%s",op) ,x=read() ,y=read() ,z=read();
		if(op[0]=='S')if(Sum(1,pos[x],pos[x])<y)modify(1,pos[x],pos[x],z);
		if(op[0]=='A')if(Sum(1,pos[x],pos[x]+siz[x]-1) < 1ll * y * siz[x]) modify(1,pos[x],pos[x]+siz[x]-1,z);
	}
	rep(i,0,n-1)printf("%lld\n",Sum(1,pos[i],pos[i]));
}


