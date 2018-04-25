#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i<=k;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<int,int> pii;
const int N= 2e5+100;
int t[N],a[N],ans[N],n;
inline void add(int x,int v){for(;x<N;x|=x+1) t[x]+=v;}
inline int sum(int x){int res=0;for(;x>=0;x&=x+1,--x) res+=t[x];return res;}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;rep(i,1,n) cin>>a[i];
	vector<pii>w;
	rep(i,1,n) w.pb(mp(a[i],i-1));
	sort(w.begin(),w.end());
	for(pii p: w){	
		int i=p.se;
		for(register int k=1;k*i+1<n&&k<n;k++) 
			ans[k]+=sum(min(k*i+k,n))-sum(k*i);
		add(i,1);
	}
	rep(i,1,n-1) cout<<ans[i]<<endl;
	return 0;
}



















