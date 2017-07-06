#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	string s;

	cin>>s;

	ll ans=0;

	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='0')
			continue;
		if(s[i]=='1')
		{
			ans++;
			while(i<s.length()&&s[i]=='1')
				i++;
			i--;
		}
	}
	if(s[0]=='1')ans=(2*ans -1);
	else
		ans=ans*2;
	printf("%lld\n",ans );
	return 0;
}
