#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll a[100007];
ll dp[100007];
ll p2[100007];
ll dp2[100007];



ll solve(ll n)
{
	dp[0]=dp2[0]=0;
	dp[1]=dp2[1]=a[1];

	ll poly=a[1];

	ll ptr2=0;

	for(int i=2;i<=n;++i)
	{
		poly=((poly+p2[i-2])%mod *a[i])%mod;
		dp[i]=(dp2[i-1] + poly)%mod;
		dp2[i]=(dp2[i-1]+dp[i])%mod;
	}

	return dp[n];

}


void preprocess()
{
	p2[0]=1;
	for (int i = 1; i < 100005; ++i)
	{
		p2[i]=(p2[i-1]*2)%mod;
	}
}


int main()
{
	ll tc,n;
	preprocess();
	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld",&n);

		for (int i = 1; i <= n; ++i)
		{
				scanf("%lld",&a[i]);
		}

		printf("%lld\n", solve(n));

	}

	return 0;
}
