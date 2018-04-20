#include <stdio.h>
#include <iostream>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
using namespace std;

const int N= 1e6+10;
const int mod=1e9+7;

int p[300005],x,y,cnt[300005];
bool isp[1000005];
int n;
int cal(int n,int k){
	if(n<k) return 0;
	else return  cal(n/k,k)+n/k;
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		if(!isp[i]) p[++p[0]]=i;
		rep(j,1,p[0]){
			if(1ll*i*p[j]>n) break;
			isp[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
//	cout<<1<<endl;
	rep(j,1,p[0]) cnt[j]=cal(n,p[j]);
	cnt[0]++;
	rep(i,1,p[0]) cnt[i]=1ll*cnt[i-1]*(cnt[i]*2+1)%mod;
	cnt[p[0]]++;
	cout<<1ll*cnt[p[0]]*500000004%mod;
}
		
