#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream> 
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define ez(i,x) for(register int i=h[x];i;i=e[i].nxt)
using namespace std;


inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}

const int N= 4e5+100;
int n,m,mx[N],ans;
int tot,c[N],v[N];
struct edge{int u,v,val;}e[N];
inline bool cmp(edge a,edge b){
	return a.val<b.val;
}
int main(){
	n=read(),m=read();
	rep(i,1,m) e[i].u=read(),e[i].v=read(),e[i].val=read();
	sort(e+1,e+m+1,cmp);
	rep(i,1,m){
		c[++tot]=e[i].u,v[tot]=mx[e[i].v]+1;
		c[++tot]=e[i].v,v[tot]=mx[e[i].u]+1;
		while(e[i+1].val==e[i].val&&i<m){i++;
			c[++tot]=e[i].u,v[tot]=mx[e[i].v]+1;
			c[++tot]=e[i].v,v[tot]=mx[e[i].u]+1;
		}
		while(tot){
			mx[c[tot]]=max(mx[c[tot]],v[tot]);tot--;
		}
		//cout<<e[i].u<<" "<<e[i].v<<" "<<mx[e[i].u]<<" "<<mx[e[i].v]<<endl;
	}
	rep(i,0,n-1) ans=max(ans,mx[i]);
	cout<<ans<<endl;
}
