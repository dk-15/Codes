#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	int t,m,n,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for (int i = 0; i < m; ++i)
		{
				cin>>u>>v;
		}
		if(n%2 == 0)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}	
	return 0;
}
