#include<bits/stdc++.h>
using namespace std;
const int N = 205;
const int M = 5005;
const double eps=1e-6;
inline int read(){
	char ch='*';
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}

struct Graph{
	int cnt;
	int h[N];
	struct edge{
		int to,next;
		double val;
	}e[M<<1];
	inline void add(int from,int to,double val){
		//;cerr<<from<<"  "<<to<<"  " <<val<<endl;
		e[++cnt]=(edge){to,h[from],val};h[from]=cnt;
		e[++cnt]=(edge){from,h[to],0};h[to]=cnt;
	}
	/*
	inline void init(){
		cnt=1;
		memset(h,0,sizeof(h));
	}
	
	void operator =(const edge & a) const{
		to=a.to;
		next=a.next;
		val=a.val;
	}
	*/
	inline void init(){cnt=1;}
}G[2];
int n,m,p;
int dis[N],cur[N];
queue<int>q;
int s,t;
bool bfs(){
	memset(dis,-1,sizeof dis);
	q.push(s);dis[s]=0;
	while(!q.empty()){
		int j=q.front();q.pop();
		for(register int i=G[0].h[j];i;i=G[0].e[i].next){
			int v=G[0].e[i].to;
			cerr<<v<<"---"<<dis[v]<<"--"<<G[1].e[i].val<<endl;
			if(dis[v]<0&&fabs(G[1].e[i].val)>eps){
				//cerr<<v<<"!!!"<<endl;
				dis[v]=dis[j]+G[1].e[i].val;
				q.push(v);
			}
		}
	}
	return dis[t]!=-1;
}


double  dfs(int x,double flow){
	if(x==t||flow<=eps) return flow;
	double a=0,tmp;
	for(register int &i=cur[x];i;i=G[0].e[i].next){
		int v=G[0].e[i].to;
		if(dis[v]==dis[x]+1&&fabs(G[1].e[i].val)>eps){
			tmp=dfs(v,min(G[1].e[i].val,flow));
			G[1].e[i].val-=tmp;
			G[1].e[i^1].val+=tmp;
			a+=tmp;
			if(fabs(flow-a)<=eps) return a;
		}
	}
	if(a<=eps) dis[x]=-1;
	return a;
}

double dinic(double  flow){
	double res=0;
	for(int i=1;i<=G[0].cnt;i++){
		G[1].e[i]=G[0].e[i];
		G[1].e[i].val=min(flow,G[1].e[i].val);
	}
	while(bfs()){
		for(int i=s;i<=t;i++)cur[i]=G[0].h[i];
		res+=dfs(s,1000000000);
	}
	return res;
}
		



int main(){
	n=read();m=read();p=read();
	s=1,t=n;
	int u,v,w;
	G[0].init();
	for(int i=1;i<=m;i++){
		u=read(),v=read(),w=read();
		G[0].add(u,v,w);
	}
	double l=0,r=1000000000,mid;
	double ans=dinic(r);
	//printf("-------------\n");
	//printf("%d\n",dinic(0x7fffffff));
	//printf("--------------\n");
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(fabs(ans-dinic(mid))<=eps) r=mid;
		else l=mid;
	}
	printf("%.0lf\n%.5lf",ans,l*p);
}
