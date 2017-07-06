#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll c[253],d[253],t[253];

ll calcPairs(ll e,ll n,ll m, ll a[] ,ll b[])
{

	ll ans=0;

	ll i=0,j=0;

	while(i<n)
	{
		while(j<m)
		{
			if(abs(a[i]-b[j])<=e)
			{
				j++;
				ans++;
				break;
			}
			j++;
		}
		i++;
	}

	return ans;


}


int main()
{

	ll tc,n,m,e;

	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld%lld%lld",&n,&m,&e);

		for (int i = 0; i < n; ++i)
		{
				scanf("%lld",&c[i]);
		}

		for (int i = 0; i < m; ++i)
		{
				scanf("%lld",&d[i]);
		}


		sort(c,c+n);
		sort(d,d+m);

		ll ans = calcPairs(e,n,m,c,d);
		ll d1,d2;
		for (int i = 0; i < m; ++i)
		{
				d1= d[i]+e-c[0];
				d2= d[i]-e-c[0];

				for (int j = 0; j < n; ++j)
				{
						t[j]=c[j]+d1;
				}

				ans = max(ans,calcPairs(e,n,m,t,d));

				if(ans == min(n,m))
					break;

				for (int j = 0; j < n; ++j)
				{
						t[j]=c[j]+d2;
				}

				ans = max(ans,calcPairs(e,n,m,t,d));

				if(ans == min(n,m))
					break;
		}

		printf("%lld\n",ans );


	}
	
	return 0;
}
