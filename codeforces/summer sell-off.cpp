#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld I64d

int k[100007],l[100007],benifit[100007];

int main()
{
	int n,f;
	scanf("%d%d",&n,&f);

	for (int i = 0; i < n; ++i)
	{
			scanf("%d%I64d",k+i,l+i);
	}


	for (int i = 0; i < n; ++i)
	{
			if(k[i]>=l[i])
				benifit[i]=0;
			else
			{
				if(2*k[i]<=l[i])
					benifit[i]=k[i];
				else
					benifit[i]=l[i]-k[i];
			}
	}
	sort(benifit,benifit+n);
	// for (int i = 0; i < n; ++i)
	// {
	// 		cout<<benifit[i]<<"  ";
	// }
	// cout<<endl;
	ll ans=0;
	for (int i = 0; i < n; ++i)
	{
			ans+=min(k[i],l[i]);
	}
	for (int i = 0; i < f; ++i)
	{
			ans+=benifit[n-1-i];
	}
	cout<<ans;
	//printf("%lld\n",ans );

	return 0;
}
