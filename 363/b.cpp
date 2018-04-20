#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define ez(x) for(register int i=h[x];i;i=e[i].nxt)

using namespace std;
inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar()))  if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}
const int N= 2e5+100;
struct edge{int to,nxt;}e[N<<1];
int n,m,cnt,a[N],h[N],siz[N],fa[N],dfn[N],low[N],tot,vis[N],root,pcnt;
int belong[N],sz[N],ans,us[N];
stack<int>s;
void add(int u,int v){
	e[++cnt]=(edge){v,h[u]};h[u]=cnt;
	e[++cnt]=(edge){u,h[v]};h[v]=cnt;
}
void dfs(int x){
	dfn[x]=low[x]=++tot;
	s.push(x);vis[x]=1;
	ez(x){
		if(e[i].to==fa[x])continue;
		if(!dfn[e[i].to]){
			fa[e[i].to]=x;
			dfs(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if(vis[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	}
	if(dfn[x]==low[x]){
		pcnt++;
		int j=s.top();
		do{
			j=s.top();s.pop();
			belong[j]=pcnt;sz[pcnt]++;
			vis[j]=0;
		}while(x!=j);
	}
}

int main(){
	n=read();
	rep(i,1,n) {a[i]=read();if(a[i]!=i) add(i,a[i]);else if(!root) root=i;}
	if(!root){
		rep(i,1,n) if(!dfn[i]){ dfs(i);}
		rep(i,1,n) {if(sz[belong[i]]>1){ a[i]=i;ans++;break;}}
		cout<<ans<<endl;
		rep(i,1,n) printf("%d ",a[i]);
		return 0;
	}
 
	dfs(root);
	rep(i,1,n) {
		if(!dfn[i]) {
			dfs(i);
			if(sz[belong[i]]>1) ans++,a[i]=root;
		}
	}
	rep(i,1,n) if(a[i]==i&&root!=i) a[i]=root,ans++;
	cout<<ans<<endl;
	rep(i,1,n) printf("%d ",a[i]);
}


