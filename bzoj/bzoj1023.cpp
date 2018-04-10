#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int N = 50005;
typedef long long ll;
inline int read(){
	char ch='*';
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num* f;
}
int n,m,cnt ,ind ,ans;
int h[N],deep[N],f[N],low[N],dfn[N],fa[N];
int a[N<<1],q[N<<1],l,r;
struct edge{int to,next;}e[20000005];
void add(int from,int to){
	e[++cnt]=(edge){to,h[from]};h[from]=cnt;
	e[++cnt]=(edge){from,h[to]};h[to]=cnt;
}
void dp(int root ,int x){
	int tot=deep[x]-deep[root]+1;
	for(int i=x;i!=root;i=fa[i])
		a[tot--]=f[i];
	a[tot]=f[root];
	tot=deep[x]-deep[root]+1;
	for(int i=1;i<=tot;i++) a[i+tot]=a[i];
	q[1]=1;l=r=1;
	for(int i=2;i<=2*tot;i++){
		while(l<=r&&i-q[l]>tot/2) l++;
		ans=max(ans,a[i]+i+a[q[l]]-q[l]);
		while(l<=r&&a[q[r]]-q[r]<=a[i]-i) r--;
		q[++r]=i;
	}
	for(int i=2;i<=tot;i++) f[root]=max(f[root],a[i]+min(i-1,tot-i+1));
}
		




void dfs(int x){
	low[x]=dfn[x]=++ind;
	for(int i=h[x];i;i=e[i].next){
		if(e[i].to!=fa[x]) {
			if(!dfn[e[i].to]){
				fa[e[i].to]=x;
				deep[e[i].to]=deep[x]+1;
				dfs(e[i].to);
				low[x]=min(low[x],low[e[i].to]);
			}
			else low[x]=min(low[x],dfn[e[i].to]);
			if(dfn[x]<low[e[i].to]){
				ans=max(ans,f[x]+f[e[i].to]+1);
				f[x]=max(f[x],f[e[i].to]+1);
			}
		}
	}
	for(int i=h[x];i;i=e[i].next)
		if(fa[e[i].to]!=x&&dfn[x]<dfn[e[i].to])
			dp(x,e[i].to);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++ ){
		int k=read(),a=read();
		for(int i=2;i<=k;i++){
			int b=read();
			add(a,b);a=b;
		}
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
