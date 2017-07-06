#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll arr[100007];

int main()
{
	ll tc,n,ans,temp,j;

	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld",&n);
		for(int i=0;i<(n<<1);++i)
			scanf("%lld",&arr[i]);

		sort(arr,arr+(n<<1));
		ans=arr[(n<<1)-(n>>1)-1];
		j=n-1;
		for(int i=(n<<1)-(n>>1)-1;i<(n<<1);++i)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			j+=2;
		}

		printf("%lld\n",ans);
		for(int i=0;i<(n<<1);++i)
			printf("%lld ",arr[i]);
		printf("\n");

	}


	return 0;
}
