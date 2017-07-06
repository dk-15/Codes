#include<bits/stdc++.h>
using namespace std;

#define ll long long

string str;
int prefix[100003];
int main()
{
	int l,r,m;
	cin>>str;
	prefix[0]=0;
	for(int i=0;i<str.length()-1;i++)
	{
		if(str[i]==str[i+1])
			prefix[i+1]=prefix[i]+1;
		else
			prefix[i+1]=prefix[i];
	}
	prefix[str.length()]=prefix[str.length()-1];
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		cout<<prefix[r-1]-prefix[l-1]<<endl;
	}
	
	// for(int i=0;i<=str.length();i++)
		// cout<<prefix[i]<<" ";
	return 0;
}