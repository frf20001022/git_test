#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
using namespace std;


const int N=1e5+10;
const int mod= 1e9+7;
typedef long long ll;
ll f[N];
int n,m;
inline int qpow(int x,int y){
	ll res=1;
	while(y){
		if(y&1) res=res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}

int main(){
	cin>>n>>m;
	n-=2,m-=2;n=n+m;f[0]=1;
	rep(i,1,n) f[i]=f[i-1]*i%mod;
	cout<<f[n]*qpow(f[m],mod-2)%mod*qpow(f[n-m],mod-2)%mod;
}










