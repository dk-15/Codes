#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool s[1000001];
std::vector<ll> primes;
ll a[5003],n;
std::map<ll, ll> m;

#define MOD 1000000007

void sieve()
{
	for (ll i = 2; i*i <=100003 ; ++i)
	{
		if(!s[i])
		{
			for (ll j = i<<1; j < 100000; j+=i)
			{
				s[j]=true;
			}
		}
	}
	for (int i = 2; i <100000 ; ++i)
	{
		if(!s[i])
		{
			primes.push_back(i);
		}
	}
}


ll power(ll x,ll y)
{
	ll res = 1;      // Initialize result
 
    x = x % MOD;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % MOD;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % MOD;  
    }
    return res;
}

int main()
{
	sieve();
	// for (int i = 0; primes[i]<100; ++i)
	// {
	// 		printf("%lld\n",primes[i] );
	// }

	scanf("%lld",&n);

	for (int i = 0; i < n; ++i)
	{
			scanf("%lld",a+i);
	}
	ll tmp;
	ll ctr;
	for (int i = 0; i < n; ++i)
	{
			tmp=a[i];
			for (std::vector<ll>::iterator it = primes.begin(); it != primes.end(); ++it)
			{
				if(tmp==1)break;
				// std::vector<ll>::iterator it2 =lower_bound(primes.begin(), primes.end(),tmp);
				// if(it2!=primes.end()&&*it2==tmp)
				// {
				// 	m[tmp]++;
				// 	tmp=1;
				// }
				ctr=0;
				while(tmp%(*it)==0)
				{
					//cout<<ctr<<endl;
					ctr++;
					tmp=tmp/(*it);
				}
				if(ctr)
					m[*it]+=ctr;
			}
			if(tmp!=1)
			{
				m[tmp]++;
			}
	}

	ll mx=0;
	bool flag=true;
	for (std::map<ll,ll>::iterator it = m.begin(); it != m.end(); ++it)
	{
		// cout<<it->first<<"  "<<it->second<<endl;
		// mx=max(mx,it->second);
		if(it->second%n!=0)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		printf("justdoit\n");
	}
	else
	{
		ll ans=1;
		for (std::map<ll,ll>::iterator it = m.begin(); it != m.end(); ++it)
		{
			// cout<<it->first<<"  "<<it->second<<endl;
			// mx=max(mx,it->second);
			if(it->second%(n+1)!=0)
			{
				ans=(ans*power(it->first,n+1-(it->second%(n+1))))%MOD;
			}
			// cout<<ans<<endl;
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
