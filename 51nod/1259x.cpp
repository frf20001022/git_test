#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;
static int n;
static int dp[50005];
const static int mod = 1e9+7;
#define inc(a,b) (a+b>=mod?a+b-mod:a+b)
int main(){
	cin>>n;dp[0]=1;
	static int i,j,lim;lim=n-3;
	for(i=1;i<=lim;i+=4){
	   for(j=i;j<=lim;j+=4) dp[j]=(dp[j]+dp[j-i])%mod,dp[j+1]=(dp[j+1]+dp[j-i+1])%mod,dp[j+2]=(dp[j+2]+dp[j-i+2])%mod,dp[j+3]=(dp[j+3]+dp[j-i+3])%mod;for(;j<=n;++j)dp[j]=(dp[j]+dp[j-i])%mod;
	   rep(k,1,n) cerr<<dp[i]<<" ";cerr<<endl;
	   for(j=i+1;j<=lim;j+=4) dp[j]=(dp[j]+dp[j-i-1])%mod,dp[j+1]=(dp[j+1]+dp[j-i])%mod,dp[j+2]=(dp[j+2]+dp[j-i+1])%mod,dp[j+3]=(dp[j+3]+dp[j-i+2])%mod;for(;j<=n;++j)dp[j]=(dp[j]+dp[j-i])%mod;
	   rep(k,1,n) cerr<<dp[i]<<" ";cerr<<endl;
	   for(j=i+2;j<=lim;j+=4) dp[j]=(dp[j]+dp[j-i-2])%mod,dp[j+1]=(dp[j+1]+dp[j-i-1])%mod,dp[j+2]=(dp[j+2]+dp[j-i])%mod,dp[j+3]=(dp[j+3]+dp[j-i+1])%mod;for(;j<=n;++j)dp[j]=(dp[j]+dp[j-i])%mod;
	   rep(k,1,n) cerr<<dp[i]<<" ";cerr<<endl;
	   for(j=i+3;j<=lim;j+=4) dp[j]=(dp[j]+dp[j-i-3])%mod,dp[j+1]=(dp[j+1]+dp[j-i-2])%mod,dp[j+2]=(dp[j+2]+dp[j-i-1])%mod,dp[j+3]=(dp[j+3]+dp[j-i])%mod;for(;j<=n;++j)dp[j]=(dp[j]+dp[j-i])%mod;
	   rep(k,1,n) cerr<<dp[i]<<" ";cerr<<endl;
	}
	for(;i<=n;i++) for(j=i;j<=n;j++) dp[j]=(dp[j]+dp[j-i])%mod;
	cout<<dp[n]<<endl;
}

