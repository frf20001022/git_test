#include <stdio.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define dow(i,j,k) for(register int i=j;i>=k;i++)
using namespace std;
const int N= 1e5+10;
int a[N],p[N],ans=1,n;

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),p[a[i]]=p[a[i]-1]+1,ans=max(ans,p[a[i]]);
	cout<<n-ans<<endl;
}
