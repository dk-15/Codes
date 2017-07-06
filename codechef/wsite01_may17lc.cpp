#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::vector<string> s;
std::vector<bool> b;
std::vector<string> ans;
ll n;

std::vector<std::map<char,ll> > m1;
std::vector<int > v1;
std::vector<std::map<char,ll> > m2;

bool pos=true;

string solve(int i,int j)
{

	for (std::map<char,ll>::iterator it = m2[i].begin(); it != m2[i].end(); ++it)
	{
		if(m1[j].find(it->first)!=m1[j].end())
		{
			v1[j]=-1;
			solve(it->second,m1[j][it->first]);
		}
	}
}

void solve2(int k,string str)
{
	if(!pos)return;
	if(v1[k]!=-1)
	{
		ans.push_back(str);
		return;
	}
	if(m1[k].empty())
	{
		pos=false;
		return;
	}
	for (std::map<char,ll>::iterator it = m1[k].begin(); it != m1[k].end(); ++it)
	{
		solve2(it->second,str+string("").append(1u,it->first));
	}
}

int main()
{
	
	scanf("%lld",&n);
	s.resize(n);
	b.resize(n);
	char ch;
	ll tlen1=0,tlen2=0;
	for (int i = 0; i < n; ++i)
	{
			cin>>ch>>s[i];
			b[i]=(ch=='-');
			if(b[i])
				tlen1+=s[i].length();
			else
				tlen2+=s[i].length();
	}
	string str;
	ll nc1=1,nc2=1;
	m1.resize(tlen1);
	m2.resize(tlen2);
	ll ptr;
	for (int i = 0; i < n; ++i)
	{
			ptr=0;
			str=s[i];
			if(b[i])
			{
				for (int j = 0; j < str.length(); ++j)
				{
					if(m1[ptr].find(str[j])!=m1[ptr].end())
					{
						ptr=m1[ptr][str[j]];
					}	
					else
					{
						m1[ptr][str[j]]=nc1;
						ptr=nc1;
						nc1++;
					}
				}

			}
			else
			{
				for (int j = 0; j < str.length(); ++j)
				{
					if(m2[ptr].find(str[j])!=m2[ptr].end())
					{
						ptr=m2[ptr][str[j]];
					}	
					else
					{
						m2[ptr][str[j]]=nc2;
						ptr=nc2;
						nc2++;
					}
				}

			}
	}

	v1.resize(nc1);


	solve(0,0);

	solve2(0,string(""));


	sort(ans.begin(), ans.end());
	bool flag = true;
	// for (int i = 1; i < ans.size(); ++i)
	// {
	// 	if(ans[i-1].compare(ans[i])==0)
	// 		flag=false;
	// 	if(!flag)
	// 		break;
	// }
	if(pos)
		{
		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i]<<endl;
		}
	}
	else
		cout<<-1<<endl;
	return 0;
}
