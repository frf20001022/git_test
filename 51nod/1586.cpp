#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
using namespace std;
const int L = 1<<16;
static int buf[L],*s=buf,*t=buf;
inline int getc(){
	if(s==t){
		t=(s=buf) +fread(buf,1,L,stdin);
		if(s==t) return EOF;
	}
	return *s++;
}
#define getc getchar
inline int read(){
	static  int ch=0;int f=1;
	while(!isdigit(ch=getc())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getc())) num=(num<<1)+(num<<3)+ch-'0';
	return num*f;
}
const int N= 1e6+100;
long long a[N],b[N],c[N];
int n,q;
static int op,x,y;
int main(){
	n=read(),q=read();
	//cerr<<"begin"<<endl;
	rep(i,1,q){
		op=read();x=read();
		//cerr<<"??"<<endl;
		if(op==1) {
			y=read();
			for(register int j=x;j<=n;j+=x)	for(register int k=j;k<=n;k+=j) c[k]+=y;
			
		}
		else printf("%lld\n",c[x]);
	}
}
















