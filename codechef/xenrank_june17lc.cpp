#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	
	ll tc,u,v,tr;

	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld%lld",&u,&v);

		tr = ((u+v+1)%2 == 0 )?(((u+v+1)/2)*(u+v)):(((u+v)/2)*(u+v+1));

		printf("%lld\n",tr+ u + 1 );


	}

	return 0;
}
