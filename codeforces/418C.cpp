#include <bits/stdc++.h>
using namespace std;
#define ll long long

char clr[1503];
ll n,q;
ll m[200003];
char c[200003

std::vector<std::vector<pair<int,int> > > v;


void preprocess()
{
	char curc;

	ll s,e;
	for (int chr = 0; chr < 26; ++chr)
	{
		curc=(char)('a'+chr);
		s=e=-1;
		for (int i = 0; i < n; ++i)
		{
			if(clr[i]==curc)
			{
				s=e=i;
				while(i<n && clr[i]==curc)
				{
					e++;
				}
				if(s!=-1)
				v[chr].push_back(make_pair(s,e-1);
			}
		}
	}



	





}


int main()
{

	scanf("%I64d",&n);
	for (int i = 0; i < n; ++i)
	{
			scanf("%c",clr+i);
	}

	v.resize(26);

	preprocess();


}