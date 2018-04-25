#include <bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;++i)
#define dow(i,j,k) for(register int i=j;i>=k;--i)
#define lowbit(x) (x&(-x))
using namespace std;
const double eps = 1e-6;
const int N= 1e5+10;
long long n,a[N];
long long k;
int t[N];
inline void add(int x,int v){for(;x<=n;x+=lowbit(x))t[x]+=v;}
inline int sum(int x){int res=0;for(;x;x-=lowbit(x))res+=t[x];return res;}
long long check(double mid)
{	//cerr<<mid<<" ";
	double tmp[N];vector<double>b;
	memset(t,0,sizeof(t));
	rep(i,0,n) tmp[i]=a[i]-i*mid+eps,b.push_back(tmp[i]);
	sort(b.begin(),b.end())	,b.erase(unique(b.begin(),b.end()),b.end());
	rep(i,0,n) tmp[i]=lower_bound(b.begin(),b.end(),tmp[i])-b.begin()+1;
//	rep(i,0,n) cerr<<tmp[i]<<" ";cerr<<endl;
	long long res=0;
	rep(i,0,n) res+=sum(tmp[i]),add(tmp[i],1);
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;rep(i,1,n) cin>>a[i],a[i]+=a[i-1];
	double l=1.0,r=100000.0,mid;
	while(fabs(r-l)>eps){
		mid=(l+r)/2.0;
		if(check(mid)>=k) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
}


