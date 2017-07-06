#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

int main()
{
	ll tc,len,i;
	scanf("%lld",&tc);
	while(tc--)
	{
		cin>>s;
		len=s.length();
		i=0;
		while(s[i]=='C'&&i<len)
			i++;
		while(s[i]=='E'&&i<len)
			i++;
		while(s[i]=='S'&&i<len)
			i++;
		if(i==len)
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
	system("pause");
}
