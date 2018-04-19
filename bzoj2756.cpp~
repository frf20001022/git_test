#include<bits/stdc++.h>
//#define p(i,j) (i*( m-1) + j)
using namespace std;

const int N = 505;
const int M = 10006;
int T,n,m,s,t;
int cnt=1,h[N],dis[N],cur[N];
int mp[50][50];
int dx[]={0,1 ,0,-1},dy[]={1,0,-1,0};
int p[N][N];
int vis[N][N];
queue<int> q;
struct edge{
	int	to,next,val;
}e[M];

inline void add(int from,int to,int val){
//	printf("%d--%d---%d\n",from,to,val);
	e[++cnt]=(edge){to,h[from],val};h[from]=cnt;
	e[++cnt]=(edge){from,h[to],0};h[to]=cnt;
}

bool bfs(){
	memset(dis,-1,sizeof(dis));
	q.push(s);dis[s]=0;
	while(!q.empty()){
		int j=q.front();q.pop();
		for(int i=h[j];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]<0&&e[i].val){
				dis[v]=dis[j]+1;
				q.push(v);
			}
		}
	}
	return dis[t]>0;
}

int dfs(int x,int flow){
	if(x==t||flow==0)return flow;
	int a=0,temp;
 
	for(int &i=cur[x];i;i=e[i].next){
		int v=e[i].to;
	       	if(dis[v]==dis[x]+1&&e[i].val){
			temp=dfs(v,min(flow-a,e[i].val));
			a+=temp;
	 		e[i].val-=temp;
			e[i^1].val+=temp;
			if(flow==a) return a;
		}
	}

	if (!a) dis[x]=-1;
	return a ;
}
      
int dinic(){
	int res=0;
	while( bfs()){
		for(int i=s;i<=t;i++){
			cur[i]=h[i];
		} 
		res+=dfs(s,0x7fffffff);
	}
	return res;      
}

void init(){
	cnt=1;
	memset(h,0,sizeof(h));
}
void solve1(){
	int sum1=0;
	int tot=0; 
	int sum=0;
	int maxn=0;
	for(register int i=1;i<=n;i++){
		for(register int  j=1;j<=n;j++){
			if((++tot)&1) sum1+=mp[i][j];
			else sum1-=mp[i][j];
			p[i][j]=tot  ;
			maxn=max(maxn,mp[i][j]);
		}
	}
	if(sum1<maxn){
		puts("-1");return 0;
	}
	tot=0;
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=n;j++){
			if((++tot) &1) {
				add(s,tot,sum1-mp[i][j]);
				sum+=sum1-mp[i][j];
				for(int k=0;k<4;k++){
					int xx=i+dx[i],yy=j+dy[i];
					if(xx>0&&xx<=n&&yy>0&&yy<=m) add(tot,p[xx][yy],1000000000);
				}
			}
			else add(tot,t,sum1-mp[i][j]);
		}
	}
	if(dinic()==sum) cout<<sum1<<endl;
	else printf("-1\n");
	return;
}
int  check(int x){
	memset(vis,0,sizeof(vis));
	int tot=0;
	init();
	for(register int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			tot++;
			if(!vis[i][j]) {
				add(s,tot,x-mp[i][j]);
				//cerr<<tot<<":"<<endl;
				for(int k=0;k<4;k++){
					int xx=i+dx[k],yy=j+dy[k];
					//cout<<xx<<"---"<<yy<<"---"<<p[xx][yy]<<endl;
					if(xx>0&&xx<=n&&yy>0&&yy<=m){
						//if((p[xx][yy]^tot)&1!=0)
						add(tot,p[xx][yy],1000000000);
						vis[xx][yy]=1;
					}
				}
			}
			else add(tot,t,x-mp[i][j]);
		}
	int fuck=dinic();
	//cout<<"fuch "<<fuck<<endl;
	return fuck;
}
void solve2(){
	int maxn=0;
	int ans=0;
	int tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			maxn=max(maxn,mp[i][j]),ans+=mp[i][j],p[i][j]=++tot;
	}
	int l=maxn,r=1000000009,mid;                 
	//cout<<"!!"<<check(3)<<endl;
	//return ;
	while(l<r){
		mid=l+r>>1;
		if(check(mid)==(1ll*n*m*mid-ans)/2) r=mid;
		else l=mid+1;
	}
	if(l>=1000000000) puts("-1");
	else printf("%d\n",(1ll*n*m*r-ans)/2);
}

int main(){
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d%d",&n,&m);
		t=n*m+1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		if(n*m&1)solve1();
		else solve2();
	}
}
