#include <bits/stdc++.h>
#define rep(i,j,k)  for(register int  i=j;i<=k;++i)
#define dow(j,k,l)  for(register int  j=k;j>=l;--j)
using namespace std;
const int N=5e4+100;
const int mod = 1e9+7;
static int dp[N][500],n;
static long long sum;
int main(){
	cin>>n;
	dp[0][0]=1;dp[1][1]=1;
	rep(i,2,n) rep(j,1,350) if(i>j)dp[i][j]=((dp[i][j]+dp[i-j][j])%mod+dp[i-j][j-1])%mod;
	rep(i,1,350) sum=(sum+dp[n][i]) %mod;
	cout<<sum<<endl;
}
