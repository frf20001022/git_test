#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i++)
#define ll long long 
const int N = 5005;
const int mod=1e9+7;
using namespace std;
int n,k,a[N];
ll C[N],fac;
ll ans[N];
inline int qpow(int x,int y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n) scanf("%d",&a[i]);
	C[1]=1;fac=1;
	rep(i,2,n){
		C[i]=C[i-1]*(k+i-2)%mod*qpow(i-1,mod-2)%mod;
	}
	rep(i,1,n){
		for(int j=i,p=1;j>=1;j--,p++)
			(ans[i]+=a[j]*C[p]%mod)%=mod;//cerr<<C[p][k-1]<<endl;
		printf("%d\n",(ans[i]+mod)%mod);
	}
}
