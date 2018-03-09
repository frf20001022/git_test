#include<bits/stdc++.h>
#define LL long long
#define debug //printf("%d - [%s]   %d\n",__LINE__,__FUNCTION__,i);

using namespace std;
int pri[8]={2,3,5,7,11,13,17,19},n,mod;
int f[500][500],dp[500][500][2];
int ans =0 ;
struct node{
	int a,p;
	bool operator < (const node &x)const{
		return p<x.p;
	}
}num[501];


void init(){
	f[0][0]=1;
	for(int i=2;i<=n;i++){
		int temp=i;
		for(int j=0;j<=7;j++){
			if(temp%pri[j]==0){
				while(temp%pri[j]==0) temp/=pri[j];
				num[i].a|=(1<<j);
			}
		}
		num[i].p=temp;
	}

}
int main(){
	scanf("%d%d",&n,&mod);
	init();
	sort(num+2,num+n+1);
	for(int i=2;i<=n;i++){
		if(num[i].p==1||num[i].p!=num[i-1].p){
			for(int j=0;j<=256;j++)
				for(int k=0;k<=256;k++)
					dp[j][k][0]=dp[j][k][1]=f[j][k];
		}
		debug
		for(int j=256;j>=0;--j)
			for(int k=256;k>=0;--k){
				if((num[i].a&k)==0)
					/*printf("k-%d j-%d num[i].a-%d j|num[i].a-%d\n ",k,j,num[i].a,num[i].a|j),*/dp[j|num[i].a][k][1]=(LL)dp[j|num[i].a][k][1]+dp[j][k][1],dp[j|num[i].a][k][1]%=mod;
					debug
				if((num[i].a&j)==0)
					dp[j][k|num[i].a][0]=((LL)dp[j][k|num[i].a][0]+dp[j][k][0])%mod;
			}
		debug
				if(num[i].p==1||num[i].p!=num[i+1].p)
					for(int j=256;j>=0;j--)for(int k=256;k>=0;k--)
						f[j][k]=((LL)dp[j][k][0]+dp[j][k][1]-f[j][k])%mod;
	}
	for(int i=0;i<=256;i++) for(int j=0;j<=256;j++){
		if((j&i) ==0) ans=(ans+f[i][j])%mod;
	}
	printf("%d\n",(ans+mod) %mod);
	return 0;
}





















