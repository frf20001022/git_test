#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dwo(i,j,k) for(register int i=j;i>=k;i++)

using namespace std;

inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar()))num=num*10+ch-'0';
	return num*f;
}
const int N= 1e5+10;
long long val[N],num[N];
int n,q;
int s[30],len;
long long S;
long long solve(int x){
	int tmp=x;
	long long res=0;
	int m=sqrt(x);len=0;
	rep(i,2,m)if(tmp%i==0){
		while(tmp%i==0) tmp/=i;
		s[++len]=i;
	}
	if(tmp!=1) s[++len]=tmp;
//	cout<<len<<endl;
//	rep(i,1,len) cerr<<s[i]<<" ";cout<<endl;
	int cnt;
	rep(i,1,(1<<len)-1){cnt=0,tmp=1;
//		cout<<"i "<<i<<" ";
		rep(j,0,len-1)if(i&(1<<j))tmp*=s[j+1],cnt++;
//		cout<<tmp<<" "<<cnt<<endl;
		if(cnt&1) res+=val[tmp];
		else res-=val[tmp];
	}
	return res;
}
void update(int x,int y){
	S-=num[x];
	int m=sqrt(x);
	rep(i,1,m)
		if(x%i==0){
			if(i*i==x) val[i]=val[i]-num[x]+y;
			else val[x/i]=val[x/i]-num[x]+y,val[i]=val[i]-num[x]+y;
		}
	num[x]=y;S+=num[x];
}
int main(){
	n=read(),q=read();
	int x;
	rep(i,1,n) num[i]=read(),S+=num[i];
	rep(i,1,n)for(int j=1;i*j<=n;j++) val[i]+=num[i*j];
//	rep(i,1,n) cerr<<val[i]<<" ";cout<<endl;
	int op,y;
//	cout<<"complete"<<endl;
	while(q--){
//		cerr<<" ________________________"<<endl;
		op=read();
		if(op==1)x=read(),y=read(),update(x,y);
		else y=read(),printf("%lld\n",S-solve(y));
	}
}
