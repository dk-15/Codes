#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100007];

int main()
{
	ll tc,n,ans;
	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		ans=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>ans)
				ans=arr[i];
		}

		printf("%lld\n",(n-ans));

	}

	return 0;
}
