#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll tc,n;
ll arr[100007],ps[100007];

ll f(int i)
{

	return ps[i-1]*i + (ps[n-1]-ps[i-1]);

}


int search(int start , int end)

{

	int mid;

	while(end-start > 1)
	{
		mid=(start+end)>>1;
		

		if(f(mid)>f(mid+1))
		{
			end=mid;
		}
		else 
		{
			start = mid;
		}

	}

	return start+1;

}


int main()
{
	scanf("%lld",&tc);

	while(tc--)
	{

		scanf("%lld",&n);

		for (int i = 0; i < n; ++i)
		{
				scanf("%lld",arr+i);
		}
		sort(arr,arr+n,greater<ll>());

		ps[0]=arr[0];

		for (int i = 1; i < n; ++i)
		{
				ps[i]=ps[i-1]+arr[i];
		}

		// for (int i = 0; i < n; ++i)
		// {
		// 		printf("%lld\n", ps[i]);
		// }

		if(arr[0]<0)
		{
			printf("%lld\n",ps[n-1] );
			continue;
		}
		if(arr[n-1]>=0)
		{
			printf("%lld\n",ps[n-1]*n);
			continue;
		}

		printf("%lld\n", f(search(-1,n))  ); 

	}	
	return 0;
}
