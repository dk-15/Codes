#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl printf("\n")


ll a[1003],b[1003],p[1003];
bool flag[1003];
ll ms[2];
int main()
{
	
	ll n;

	scanf("%I64d",&n);

	for (int i = 0; i < n; ++i)
	{
			scanf("%I64d",a+i);
	}

	for (int i = 0; i < n; ++i)
	{
			scanf("%I64d",b+i);
	}

	ll msc=0;


	for (int i = 0; i < n; ++i)
	{
			if(a[i]==b[i])
				{p[i]=a[i];flag[a[i]]=true;}
			else
			{
				ms[msc++]=i;
				p[i]=0;
			}
	}

	if(msc==1)
	{
		for (int i = 1; i <= n; ++i)
		{
				if(!flag[i])
				{
					p[ms[0]]=i;
				}
		}
	}
	else
	{
		p[ms[0]]=a[ms[0]];
		p[ms[1]]=b[ms[1]];

		if(!flag[a[ms[0]]])
		{
			p[ms[0]]=a[ms[0]];
			p[ms[1]]=b[ms[1]];
		}
		else
		{
			p[ms[0]]=b[ms[0]];
			p[ms[1]]=a[ms[1]];
		}

	}

	for (int i = 0; i < n; ++i)
	{
			printf("%I64d ", p[i]);
	}

	return 0;

}
