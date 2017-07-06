#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	int tc,n,upc,dnc,upu,dnu;
	string s;
	scanf("%d",&tc);
	while(tc--)
	{
		cin>>s;

		upu=dnu=1;
		upc=dnc=0;

		for (int i = 0; i < s.length(); ++i)
		{
				if(s[i]=='U')
				{
					upc=upc+upu;
					upu=0;
					dnu=1;
				}
				else
				{
					dnc=dnc+dnu;
					dnu=0;
					upu=1;
				}
		}

		printf("%d\n",min(upc,dnc) );

	}	
	return 0;
}
