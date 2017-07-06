#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl printf("\n")



ll a[105],b[105];

int main()
{

	ll n,k;
	scanf("%I64d %I64d",&n,&k);

	for (int i = 0; i < n; ++i)
	{
			scanf("%I64d",a+i);
	}
	for (int i = 0; i < k; ++i)
	{
			scanf("%I64d",b+i);
	}

	sort(b,b+k);

	ll idx=-1,zc= 0;
	for (int i = 0; i < n; ++i)
	{
			if(a[i]==0){
				zc++;
				idx=i;
			}
			if(zc==2)
			{
				printf("Yes\n");
				return 0;
			}
	}

	if(idx!=-1)
		a[idx]=b[0];

	if(is_sorted(a,a+n))
		printf("No\n");
	else
		printf("Yes\n");

	return 0;
}
