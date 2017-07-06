#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000007 


ll x[100003],y[100003],z[100003],px[100003],ys[100003],pz[100003];



int main()
{

	ll tc,p,q,r;
	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld%lld%lld",&p,&q,&r);

		for (int i = 0; i < p; ++i)
		{
				scanf("%lld",&x[i]);
		}

		for (int i = 0; i < q; ++i)
		{
				scanf("%lld",&y[i]);
		}
		for (int i = 0; i < r; ++i)
		{
				scanf("%lld",&z[i]);
		}


		sort(x,x+p);
		sort(y,y+q);
		sort(z,z+r);

		px[0]=x[0];

		for (int i = 1; i < p; ++i)
		{
				px[i]=(px[i-1]+x[i])%mod;
		}

		pz[0]=z[0];

		for (int i = 1; i < r; ++i)
		{
				pz[i]=(pz[i-1]+z[i])%mod;
		}



		ll ans=0;
		ll xptr=0,zptr=0;
		for (int i = 0; i < q; ++i)
		{
				while(xptr < p && x[xptr]<=y[i])
					xptr++;
				while(zptr < r && z[zptr]<=y[i])
					zptr++;



				xptr--;
				zptr--;
				 // printf("%lld %lld\n",xptr,zptr );
				
				//if(xptr>=0 && zptr>=0)
				//{
					ans = (((( ans + ((((zptr+1)*px[xptr])%mod)*y[i]%mod))%mod  + ((((xptr+1)*pz[zptr])%mod)*y[i]%mod))%mod + (px[xptr]*pz[zptr])%mod)%mod + (((((xptr+1)*(zptr+1))%mod)*(y[i])%mod)*y[i])%mod)%mod ; 
				//}

				// printf("%lld\n", ans);

		}


		printf("%lld\n", ans);



	}
	
	return 0;
}
