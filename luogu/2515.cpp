#include<bits/stdc++.h>
#define RG register
#define il inline 
using namespace std;
inline int read(){
	char ch='*';
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}
const int N= 100+5;

int dfn[N],low[N],vis[N],bel[N],tot,pcnt,fa[N];
int n,m,W[N],V[N],D[N];
int dp[105][505];
int h[N],cnt;
int weight[N],val[N];
int in[N];
struct edge{
	int to,next;
}e[N<<1];

stack<int> s;
inline void add(int from,int to){
	e[++cnt]=(edge){to,h[from]};h[from]=cnt;
}

void tarjan(RG int x){
	dfn[x]=low[x]=++tot;
	s.push(x),vis[x]=1;
	for(int i=h[x];i;i=e[i].next){
		int v=e[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]){
			low[x]=min(low[x],dfn[v]);
		}
	}

	if(low[x]==dfn[x]){
		pcnt++;
		int j;
		do{
			j=s.top();s.pop();
			bel[j]=pcnt;
			vis[j]=0;
		}while(j!=x);
	}
}


void dfs(int x){
	for(RG int i=weight[x];i<=m;i++) dp[x][i]=val[x];
	for(RG int i=h[x];i;i=e[i].next){
		dfs(e[i].to);
		for(int j=m;j>=weight[x];j--){
			for(int k=0;k<=j-weight[x];k++){
				dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[e[i].to][k]);
			}
		}
	}
}


int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++) W[i]=read();
	for(int i=1;i<=n;i++) V[i]=read();
	for(int i=1;i<=n;i++) {D[i]=read();if(D[i]==0)continue;else add(fa[i],i);}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	
	memset(e,0,sizeof(e));
	memset(h,0,sizeof(h));
	cnt=0;
	for(int i=1;i<=n;i++) {
		val[bel[i]]+=V[i];weight[bel[i]]+=W[i];
		if(bel[i]!=bel[D[i]]&&D[i]) add(bel[D[i]],bel[i]),in[bel[i]]++;
	}
	for(int i=1;i<=pcnt;i++){
		if(!in[i]) add(pcnt+1,i);
	}
	dfs(pcnt+1);
	printf("%d\n",dp[pcnt+1][m]);
}










