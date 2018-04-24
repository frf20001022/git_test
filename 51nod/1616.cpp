#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
using namespace std;


inline int read(){
	register char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;register int num=ch-'0';
	while(isdigit(ch=getchar())) num=(num<<1)+(num<<3)+ch-'0';
	return num*f;
}
const int N= 1e5+10;
int n,x,cnt[N];
int ans,g;
inline int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int main(){
	n=read();x=read(),cnt[x]=1,g=x;
	rep(i,2,n){x=read(),cnt[x]=1,g=gcd(g,x);}
	if(g==1) cnt[1]=1;
	dow(i,100000,1){if(cnt[i]) {ans++;continue;}
		register int j;
		for(j=2;j*i<=100000;j++) if(cnt[i*j]) break;
		if(j*i>100000) continue;
		int g=j;
		for(;j*i<=100000;j++){if(cnt[i*j]) g=gcd(g,j);if(g==1) break;}
		if(g==1) ans++,cnt[i]=1;
	}
	cout<<ans<<endl;
}


