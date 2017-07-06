#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll n,k,a[35];
double alog[35],klog;
 
std::map<ll, std::map<double, ll> > m;
 
ll solve(ll ptr,double sum)
{
	if(sum>klog)
		return 0;
	if(ptr==n)
		return sum<=klog;
	if(m.find(ptr)!=m.end() && m[ptr].find(sum)!=m[ptr].end())
		return m[ptr][sum];
	ll ans=0;
	ans+=solve(ptr+1,sum);
	ans+=solve(ptr+1,sum+alog[ptr]);
	return m[ptr][sum]=ans;
}
 
int main()
{
 
	scanf("%lld%lld",&n,&k);
	for (int i = 0; i < n; ++i)
	{
			scanf("%lld",&a[i]);
	}
 
	klog=log(k);
	for (int i = 0; i < n; ++i)
	{
			alog[i]=log(a[i]);
	}
 
 
	sort(alog,alog+n);
	// cout<<klog<<"\n";
	// for (int i = 0; i < n; ++i)
	// {
	// 		cout<<alog[i]<<"  ";
	// }
	// cout<<endl;
	cout<<solve(0,0)-1<<endl;
 
	//cout<<m[1][0]<<endl;
 
	return 0;
}