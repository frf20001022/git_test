#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;

const int N = 104;
int n,a[N],dp[N][3];

int main(){
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) {
		if(a[i]==1||a[i]==3) dp[i][1]=max(dp[i][1],max(dp[i-1][0]+1,dp[i-1][2]+1));
		if(a[i]==2||a[i]==3) dp[i][2]=max(dp[i][2],max(dp[i-1][0]+1,dp[i-1][1]+1));
		dp[i][0]=max(dp[i][0],max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]));
	}
	cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
}
