#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)

using namespace std;

const int N=1e5+100;
int a[N],b[N],n,t,k;
priority_queue<int>A,B,C;
long long sum;
bool c[N];
int ans;

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>t>>k;
	rep(i,1,n) cin>>a[i];rep(i,1,n) cin>>b[i];rep(i,1,n) cin>>c[i];
	rep(i,1,n){
		if(c[i]) {
			if(A.size()<k) A.push(b[i]);
			else A.push(b[i]),B.push(A.top()),A.pop();
		} else B.push(b[i]);
		sum+=b[i];
		if(A.size()<k) continue;
		while(sum+a[i]>t&&(!B.empty())) sum-=B.top(),C.push(-B.top()),B.pop();
		while(!C.empty()&&sum+a[i]-C.top()<=t) sum-=C.top(),B.push(-C.top()),C.pop();
	    while(!C.empty()&&-C.top()<B.top()){
			sum-=C.top(),B.push(-C.top());C.pop();
			while(sum+a[i]>t&&(!B.empty())) sum-=B.top(),C.push(-B.top()),B.pop();
		}
		if(sum+a[i]<=t&&k+B.size()>ans) ans=k+B.size();
	}
	cout<<ans<<endl;
}
		
