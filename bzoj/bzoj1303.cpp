#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100006;
int num[N],l[N],r[N],sum[N];
int n,point ,b,ans;
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		if(num[i]>b) num[i]=1;
		else if(num[i]==b) { num[i]=0,point=i;}
		else num[i]=-1;
	}
	l[n]=1;r[n]=1;
	for(int i=point-1;i;i--){
		sum[i]=sum[i+1]+num[i];l[sum[i]+n]++;
	}
	for(int i=point +1;i<=n;i++){
		sum[i]=sum[i-1]+num[i];r[sum[i]+n]++;}
	for(int i=0;i<=2*n-1;i++) ans+=l[i]*r[2*n-i];
	printf("%lld",ans);
	return 0 ;
}
