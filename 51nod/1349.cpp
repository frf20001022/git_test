#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <stack>

#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)
#define debug //printf("%d\n",__LINE__);
inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}
using namespace std;
const int N= 300005;
stack<int>s;
long long a[N],n,m,sum[N];
long long l[N],r[N];
int main(){
	cin>>n;
	rep(i,1,n) a[i]=read();
	debug
	rep(i,1,n){while(!s.empty()&&a[s.top()]<a[i]) r[s.top()]=i-1,s.pop();s.push(i);}
	while(!s.empty()) r[s.top()]=n,s.pop();
	dow(i,n,1){while(!s.empty()&&a[s.top()]<=a[i]) l[s.top()]=i+1,s.pop();s.push(i);}
	while(!s.empty()) l[s.top()]=1,s.pop();
	debug
	rep(i,1,n)sum[a[i]]+=(i-l[i])+(r[i]-i)+1ll*(i-l[i])*(r[i]-i)+1;dow(i,100000,1)sum[i]+=sum[i+1];
	debug
	m=read();int k;
	rep(i,1,m) k=read(),printf("%lld\n",sum[k]);
}

	
