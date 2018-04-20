#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;


const int mod = 1e9+7;
int n,m,ans,o,f[2][50001];
int main(){
	scanf("%d",&n);m=sqrt(n*1.0);
	f[o][0]=1;
	rep(i,1,m) {o=!o;
		rep(j,0,i-1) f[o][j]=f[!o][j];
		rep(j,i,n) f[o][j]=(f[o][j-i]+f[!o][j])%mod;
	}
	ans=f[o][n];
	rep(i,1,m){o=!o;
		rep(j,0,n){
			f[o][j]=0;
			if(j>m) f[o][j]=f[!o][j-(m+1)];
			if(j>=i) f[o][j]=(f[o][j]+f[o][j-i])%mod;
		}
		ans=(ans+f[o][n])%mod;
	}
 	cout<<ans;
}
