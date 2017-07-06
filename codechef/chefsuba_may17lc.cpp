#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[100007]; 
list<ll> w;
multiset<ll> v;
multiset<ll>::iterator it;
string str;

void preprocess(ll n,ll k)
{
	ll window=0;
	for (int i = 0; i<k && i<n; ++i)
	{
		window+=a[i];	
	}
	w.push_back(window);
	v.insert(window);
	ll ptr=1;
	while(ptr<=n-k)
	{
		window=window-a[ptr-1]+a[ptr+k-1];
		w.push_back(window);
		v.insert(window);
		ptr++;
	}

}

int main()
{
	ll n,k,p,nval,oval;
	scanf("%lld%lld%lld",&n,&k,&p);
	for (int i = 0; i < n; ++i)
	{
			scanf("%d",&a[i]);
	}
	k=min(n,k);
	preprocess(n,k);
	// for (std::multiset<ll>::iterator i = v.begin(); i != v.end(); ++i)
	// {
	// 	cerr<<*i<<" ";
	// }
	// cerr<<endl;
	ll s=0,e=n-1;
	char ch;
	cin>>str;
	int j=0;
	while(p--)
	{
		ch=str[j++];
		//cerr<<ch<<endl;
		if(ch=='?')
		{
			it=v.end();
			it--;
			printf("%lld\n",*it);
		}
		else
		{
			nval=w.front()-a[(s+k-1)%n]+a[e];
			oval=w.back();
			// cerr<<s<<" "<<e<<endl;
			w.pop_back();
			w.push_front(nval);
			v.erase(v.find(oval));
			v.insert(nval);
			s=(n+(s-1))%n;
			e=(n+(e-1))%n;
			// cerr<<w.front()<<" "<<w.back()<<endl;
	// 		for (std::multiset<ll>::iterator i = v.begin(); i != v.end(); ++i)
	// {
	// 	cerr<<*i<<" ";
	// }
	// cerr<<endl;
		}
	}
	return 0;
}
