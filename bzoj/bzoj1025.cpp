#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pa;
const int inf = 1000000000;
typedef long long ll;
const int N = 1005;
int n,tot,pri[N];
ll ans,f[N][N];
bool mark[N];
void init(){
	for(int i=2;i<=1000;i++){
		if(!mark[i]) pri[++tot]=i;
		for(int j=1;j<=tot&&i*pri[j];j++){
			mark[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}

int main(){
	scanf("%d",&n);
	init();
	f[0][0]=1;
	for(int i=1;i<=tot;i++){
		for(int j=0;j<=n;j++) f[i][j]=f[i-1][j];
		for(int j=pri[i];j<=n;j*=pri[i])
			for(int k=0;k<=n-j;k++)
				f[i][k+j]+=f[i-1][k];
	}
	for(int i=0;i<=n;i++) ans+=f[tot][i];
	printf("%lld",ans);
}


