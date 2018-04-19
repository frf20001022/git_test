#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)

using namespace std;

typedef long long ll;
const int N = 1e6+100;
const int mod = 1e9+7;

int n,m;
int dp[N],f[2][N];
ll cnt[25];



int main(){
	cin>>n>>m;
	int now=0,pre=1;
	rep(i,1,n/2) f[pre][i]=1,f[pre][i]+=f[pre][i-1]; cnt[1]=n/2;
	rep(i,2,log2(n/2)+2){ rep(j,1,n){
			f[now][j]=(f[pre][j/2]+f[now][j-1])%mod;
			//cnt[i]+=f[now][j];if(cnt[i]>=mod) cnt[i]-=mod;
		}
		cnt[i]=f[now][n]-f[now][n/2]; cnt[i]%=mod;cnt[i]=(cnt[i]+mod)%mod;
		pre^=1;now^=1;
	}
	//rep(i,1,n/2) cerr<<i<<" "<<cnt[i]<<endl;
	dp[0]=1;
	rep(i,0,m) {
		rep(j,2,log2(n/2)+2) dp[i+j]= (1ll*dp[i+j]+1ll*cnt[j]*dp[i]%mod)%mod;
		dp[i+1] = (1ll* dp[i+1]+ 1ll*(dp[i])*(n-n/2)%mod)%mod;
	}
	cout<<(dp[m]%mod+mod)%mod<<endl;
}




