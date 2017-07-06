#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::vector<std::vector<int> > v;
std::vector<int> lv;
bool kv[2503];

bool solve(std::vector<int> &v1 , std::vector<int> &v2 , ll k)
{

	for (int i = 0; i <= k; ++i)
	{
			kv[i]=false;
	}

	int cnt=0;

	for (int i = 0; i < v1.size(); ++i)
	{
			cnt += (kv[v1[i]]^true);
			kv[v1[i]]|=true;
	}
	for (int i = 0; i < v2.size(); ++i)
	{
			cnt += (kv[v2[i]]^true);
			kv[v2[i]]|=true;
	}
	return (cnt == k) ;
}


int main()
{
	
	ll tc,n,k,len;

	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld %lld",&n,&k);
		v.clear();lv.clear();
		v.resize(n);
		lv.resize(n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&len);
			v[i].resize(len);
			lv[i]=len;
			for (int j = 0; j < len; ++j)
			{
					cin>>v[i][j];
			}
			
		}
		ll ans=0;
		for (int i = 0; i < n-1; ++i)
		{
				for (int j = i+1; j < n; ++j)
				{
						if((lv[i]+lv[j])>=k)
						{
							ans+=solve(v[i],v[j],k);
						}
				}
		}


		printf("%lld\n",ans );



	}

	return 0;
}
