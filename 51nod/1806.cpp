#include  <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)

using namespace std;
typedef long long ll;
const int N=1e5+100;
const int mod= 1e9+7;
int n,m,u[21],d[21];
long long f[N],inv[N];

inline long long qpow(int x,int y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
bool ff=0;
int main(){
	scanf("%d%d",&n,&m);
	if(n==1){if(m==1) {puts("0");return 0;}
		else {puts("1");return 0;}
	}
	rep(i,1,m) scanf("%d%d",&u[i],&d[i]);
	f[0]=1;
	rep(i,1,100000) f[i]=f[i-1]*i%mod;
	inv[100000]=qpow(f[100000],mod-2);
	dow(i,99999,0) inv[i]=inv[i+1]*(i+1)%mod;
	ll ans=qpow(n,n-2);
//	cerr<<1<<endl;
	rep(i,1,(1<<m)-1){
		ff=0;
		int vis[20],cnt=0,sum=0;
		ll t=1;
		memset(vis,0,sizeof(vis));
		rep(j,1,m){
			if(i&(1<<(j-1))){
				if(vis[u[j]]) ff=1;
				cnt++,sum+=(d[j]-1);
				vis[u[j]]=1;
				t=t*inv[d[j]-1]%mod;
			}
		}
	//	cerr<<2<<endl;
		if(ff) continue;
		if(sum>n-2) continue;
	//	cerr<<3<<endl;
	//	cout<<n-2<<" "<<n-2-sum<<endl;
		ll tmp=f[n-2]*inv[n-2-sum]%mod;
		tmp=tmp*qpow(n-cnt,n-2-sum)%mod;
		tmp=tmp*t%mod;
	//	cerr<<4<<endl;
		if(cnt&1) ans=(ans-tmp)%mod+mod;
		else ans+=tmp;
		ans%=mod;
	}
	ans=ans%mod+mod;ans%=mod;
	printf("%lld\n",ans);
}







