#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld I64d
#define nl printf("\n")




int main()
{
	int n,k,p,sum=0;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i)
	{
			scanf("%d",&p);
			sum+=p;
	}
	int ans=n*(2*k-1)-2*sum;
	printf("%d\n",max(ans,0));
	return 0;	
}
