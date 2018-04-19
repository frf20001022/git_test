#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>

#define p(a,b) ((a-1)*n+b)
using namespace std;
const int N = 1005;
const int M = 100005;
struct edge{
	int to,next,val;
}e[M];
int h[N],dis[N],cur[N],cnt=1,w[N];
int mp[N][N],d[N];
int n;
queue<int> q;
int s,t,T;
int ans;
int sum;
bool flag;
inline void add(int from,int to,int val)
{
	//printf("%d--%d---%d\n",from,to,val);
    e[++cnt].next=h[from];
    e[cnt].to=to;
    e[cnt].val=val;
    h[from]=cnt;
    e[++cnt].next=h[to];
    e[cnt].to=from;
    e[cnt].val=0;
    h[to]=cnt;
}
inline bool bfs()
{
    memset(dis,-1,sizeof(dis));
    dis[s]=0;	
    q.push(s);
    int j;
    while(!q.empty()){
        j=q.front();q.pop();
        for(register int i=h[j];i;i=e[i].next)
        {
            int v=e[i].to;
            if(dis[v]<0&&e[i].val>0)
            {
                dis[v]=dis[j]+1;
                q.push(v);
                
            }
        }
    }
    return dis[t]>0;
}
int find(int x,int flow)
{
    if(x==t||flow==0) return flow;
    int a=0;
    int f=0;
    for(register int &i=cur[x];i;i=e[i].next)
    {
        //int v=e[i].to;
        if(e[i].val&&dis[x]<dis[e[i].to])
        {
            f=find(e[i].to,min(e[i].val,flow-a));
            e[i].val-=f;
            
            e[i^1].val+=f;
            a+=f;
            if(a==flow)break;
        }
    }
    if(!a) dis[x]=-1;
    return a;
}
inline int dinic()
{
    register int ans=0;
    while(bfs())
    {
        for(register int i=s;i<=t;i++) cur[i]=h[i];
        ans+=find(s,0x7fffffff);
    }
    return ans;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&d[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]),ans+=mp[i][j];
		ans>>=1;
		//cout<<T<<"TTTTTTTTTTT"<<endl;
		s=0,t=n*n+n+1;
		for(int i=1;i<=n;i++){
			flag=0;
			memset(h,0,sizeof(h));
			cnt=1;
			sum=w[i];
			//cout<<w[i]<<"  "<<sum<<endl;
			for(int j=1;j<=n;j++) sum+=mp[i][j];//cout<<j<<"??????"<<mp[i][j]<<endl;;
			//cout<<i<<"----"<<sum<<endl;
			cnt=1;
			for(int j=1;j<=n;j++)if(j!=i){
				for(int k=j+1;k<=n;k++)if(k!=i){
					if(mp[j][k]){
				 		add(s,p(j,k)+n,mp[j][k]);
						add(p(j,k)+n,j,1000000000);
						add(p(j,k)+n,k,1000000000);
					}
				}
				add(j,t,sum-w[j]);
				
				if(sum-w[j]<0) {flag=1;break;}
			}
			//cout<<"sb"<<endl
			if(flag) continue;
			//cout<<"dinic"<<endl;
			int temp=dinic();
			//printf("%d----------\n",temp);
			if(temp==ans-sum+w[i]&&!flag) printf("%d ",i);
			//cout<<ednl;
			//cout<<"--------------------------------"<<endl;
		}
		cout<<endl;
		//cout<<T<<"TTTTTTTTTTTTTTTT"<<endl;
	}
	return 0;
}
			
			
