#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N=105;
int map[N][N],w[N],v[N],x[N],y[N],head[N],k=0,low[N],sta[N],top=0,dfn[N],tim=0,color[N],color_time=0,n,m,rd[N],dp[N][505],wei[N],val[N];
bool vis[N];
struct node
{
    int to,next,w;
}edge[N*2];
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void tarjan(int x)
{
    low[x]=dfn[x]=++tim;
    s.push(x);vis[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        if(!dfn[edge[i].to])tarjan(edge[i].to),low[x]=min(low[x],low[edge[i].to]);
        else if(vis[edge[i].to])low[x]=min(low[x],dfn[edge[i].to]);
    }
    if(dfn[x]==low[x])
    {
        ++color_time;
        vis[x]=false;
        int abc
        do//(sta[top+1]!=x)
        {
        	abc=s.top(),s.pop();
            color[abc]=color_time;
            vis[abc]=false;
        }while(
    }
}
void dfs(int x)
{
    for(int i=wei[x];i<=m;i++)dp[x][i]=val[x];
    for(int i=head[x];i;i=edge[i].next)
    {
        dfs(edge[i].to);
        for(int j=m-wei[x];j>=0;j--)
        {
            for(int q=0;q<=j;q++)
            {
                dp[x][j+wei[x]]=max(dp[x][j+wei[x]],dp[x][j+wei[x]-q]+dp[edge[i].to][q]);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&y[i]);
        if(y[i]==0)continue;
        add(y[i],i);//此处注意
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    memset(edge,0,sizeof(edge));
    memset(head,0,sizeof(head));
    k=0;
    for(int i=1;i<=n;i++)
    {
        val[color[i]]+=v[i];wei[color[i]]+=w[i];
        if(color[i]!=color[y[i]]&&y[i]!=0)
        add(color[y[i]],color[i]),rd[color[i]]++;//此处注意
    }
    for(int i=1;i<=color_time;i++)
    if(rd[i]==0)add(color_time+1,i);
    dfs(color_time+1);
    printf("%d",dp[color_time+1][m]);
}
