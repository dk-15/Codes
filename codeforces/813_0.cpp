#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl printf("\n")


ll a[1003];

int main()
{
	

	ll n,m,l,r,sum=0,ans=-1;
	bool flag = false;
	scanf("%I64d",&n);

	for (int i = 0; i < n; ++i)
	{
			scanf("%I64d",a+i);
			sum += a[i];
	}
	scanf("%I64d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%I64d %I64d", &l, &r);
		if(l<=sum && sum<=r) {
			ans = sum;
			flag = true;
		}
		else if(!flag && l > sum) {
			ans = l;
			flag = true;
		}
	}
	printf("%I64d", ans);
	return 0;
}
