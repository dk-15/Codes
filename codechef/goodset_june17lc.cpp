#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	

	ll tc,n;

	cin>>tc;

	while(tc--)
	{
		cin>>n;

		ll ptr=1;

		for (int i = 0; i < n; ++i)
		{
				printf("%d ", ptr);
				ptr+=2;
		}

		printf("\n");

	}

	return 0;
}
