#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	ll tc,rm,m,e,bar,g;
	string s;
	scanf("%lld",&tc);
	while(tc--)
	{
		for (int i = 0; i < 4; ++i)
		{
		cin>>s>>g;
		if(s[0]=='R')rm=g;
		else if(s[0]=='M')m=g;
		else if(s[0]=='E')e=g;
		else bar=g;
				
		}

		if(bar>e && rm < m)
			printf("Barcelona\n");
		else
			printf("RealMadrid\n");

	}
	return 0;
}
