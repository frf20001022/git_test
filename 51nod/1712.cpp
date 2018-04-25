#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)
using namespace std;
const int N= 1e6+100;
int n;
unsigned int lrk[N],rrk[N],pre[N],nxt[N],pos[N];
unsigned int a[N],f[N],g[N],dl[N],dr[N],ans;

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n) {
		pre[i]=pos[a[i]],pos[a[i]]=i;
		lrk[i]=lrk[pre[i]]+1;
		dl[i]=dl[pre[i]]+pre[i];
	}
	memset(pos,0,sizeof(pos));
	dow(i,n,1){
		nxt[i]=pos[a[i]],pos[a[i]]=i;
		rrk[i]=rrk[nxt[i]]+1;
		dr[i]=dr[nxt[i]]+nxt[i];
	}
	rep(i,1,n){
		if(rrk[i]==1){
			nxt[i]=i+n,pre[i+n]=i;
			lrk[nxt[i]]=lrk[i]+1;
			dl[i+n]=dl[i]+i;
		}
		if(lrk[i]==1){
			pre[i]=i+n*2;nxt[i+n*2]=i;
			rrk[pre[i]]=rrk[i]+1;
			dr[i+n*2]=dr[i]+i;
		}
	}
	rep(i,1,n) f[i]=f[i-1]+i*rrk[i]-dl[nxt[i-1]];
	dow(i,n,1) g[i]=g[i+1]+i*lrk[i]-dr[pre[i+1]];
	rep(i,1,n) f[i]=f[i]+g[i]-i*2;
	memset(g,0,sizeof(g));memset(dl,0,sizeof(dl));
	rep(i,1,n){dl[i]=dl[pre[i]]+(pre[i]>=1&&pre[i]<=n);if(rrk[i]==1) dl[i+n]=dl[i]+1;}
	rep(i,1,n){
		g[i]=g[i-1]+rrk[i]-dl[nxt[i-1]];
		f[i]=(g[i]-1)*i*2-f[i];
		ans+=f[i]*a[i];
		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
