#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i--)
#define mk(i,j) make_pair(i,j)
#define fi first 
#define se second

inline int read(){
	char ch='*';int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f= -1; int num=ch-'0';
	while(isdigit(ch=getchar())) num=num*10+ch-'0';
	return num*f;
}

using namespace std;
const int N= 505;
int n,m,a[N][N],d[N];
int st[N],top;
int ans,l[N];
int main()
{
#ifndef ONLINE_JUDGE
	//freopen("out.out","w",stdout);
#endif
	n=read();m=read();
	rep(i,1,n) rep(j,1,m) a[i][j]=read();
	rep(i,1,m) rep(j,1,n){if(a[j][i]) d[i]++;else break;}
	rep(i,1,m) d[i]++;
	rep(i,1,n) {
		rep(j,1,m){
			if(d[j]>0) d[j]--;
			else if(a[i][j])rep(k,i,n){if(a[k][j]) d[j]++;else break;}
			int len=0;
			while(top&&d[j]<d[st[top]])len+=l[top],ans=max(ans,len*d[st[top]]),top--;
		    st[++top]=j,l[top]=len+1;
		//	cout<<ans<<" ";
		}
		//cout<<ans<<endl;
		int len=0;
		while(top){len+=l[top];ans=max(ans,len*d[st[top]]),top--;}
	}
	cout<<ans<<endl;
}	
			
				

