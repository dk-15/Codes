#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll h[100007],fwd[100007],bwd[100007];

int main()
{
	ll tc,n,sum;	
	scanf("%lld",&tc);
	while(tc--)
		{
			scanf("%lld",&n);
			sum=0;
			for (int i = 1; i <= n; ++i)
			{
					scanf("%lld",h+i);
					sum+=h[i];
			}

			fwd[0]=bwd[n+1]=0;

			for (int i = 1; i <=n; ++i)
			{
					if(h[i]>=i)
						fwd[i]=fwd[i-1]+1;
					else
						fwd[i]=min(h[i],fwd[i-1	]+1);
			}

			for (int i = 1; i <= n; ++i)
			{
					if(h[n+1-i]>=i)
						bwd[n+1-i]=bwd[n+2-i]+1;
					else
						bwd[n+1-i]=min(h[n+1-i],bwd[n+2-i]+1);
			}

			ll mx=-1;
			// for (int i = 1; i <= n; ++i)
			// {
			// 		printf("%lld  %lld\n",fwd[i],bwd[n+1-i] );
			// }
			for (int i = 1; i <= n; ++i)
			{
					mx=max(mx,fwd[i]+bwd[i]-1);
			}
			mx=(mx-1)/2;
			printf("%lld\n", sum - (mx+1)*(mx+1));

		}

	return 0;
}
