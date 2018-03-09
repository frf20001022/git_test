#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N],dp[N*N],n;
int k;
bool cmp(int x,int y){return x<y;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++) a[i]-=a[1];
	memset(dp,0x3f,sizeof dp);	
	dp[0]=0;
	for(int i=2 ;i<=n;i++){
		for(int j=a[i];j<=a[n]*k;j++){
				dp[j]=min(dp[j],dp[j-a[i]]+1);
		}
	}
	for(int i=0;i<=a[n]*k;i++){
		if(dp[i]<=k) printf("%d ",i+a[1]*k);
	}
	puts("");
	return 0;
}
