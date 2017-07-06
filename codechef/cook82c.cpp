#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::map<int, int> tree[100003<<2];
pair<int,int> edges[1000003];
void build(int start, int end, int index)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[index][edges[start].first]=1;
		tree[index][edges[start].second]=1;
		return;
	}
	
	build(start,(start+end)>>1,index<<1);
	build(((start+end)>>1)+1,end,(index<<1)+1);
	for (std::map<int,int>::iterator it = tree[index<<1].begin(); it != tree[index<<1].end(); ++it)
	{
		tree[index][it->first]+=it->second;
	}
	for (std::map<int,int>::iterator it = tree[(index<<1)+1].begin(); it != tree[(index<<1)+1].end(); ++it)
	{
		tree[index][it->first]+=it->second;
	}
}

map<int,int> query(int start,int end,int index,int l,int r)
{
	if(start>end || start>r || end<l)
		{
			 map<int,int> a;
			 return a;
		}
	if(start>=l && end<=r)
		return tree[index];
	map<int,int> r1,r2,r3;
	r1=query(start,(start+end)>>1,index<<1,l,r);
	r2=query(((start+end)>>1)+1,end,(index<<1)+1,l,r);
	for (std::map<int,int>::iterator it = r1.begin(); it != r1.end(); ++it)
	{
		r3[it->first]+=it->second;
	}
	for (std::map<int,int>::iterator it = r2.begin(); it != r2.end(); ++it)
	{
		r3[it->first]+=it->second;
	}
	return r3;
}

int main()
{
	ll n,m;
	int x,y,l,r;
	scanf("%lld%lld",&n,&m);
	for (int i = 0; i < m; ++i)
	{
			scanf("%d%d",&x,&y);
			edges[i]=make_pair(x,y);
	}
	build(0,n-1,1);
	for (std::map<int,int>::iterator it = tree[2].begin(); it != tree[2].end(); ++it)
		{
			cout<<it->first<<" "<<it->second<<endl;	
		}
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d",&l,&r);
		map<int,int> res=query(0,n-1,1,l-1,r-1);

		bool flag=true;
		// cout<<res.size();
		for (std::map<int,int>::iterator it = res.begin(); it != res.end(); ++it)
		{
			cout<<it->first<<" "<<it->second<<endl;	
			if(it->second%2 != 0)
				{
					flag = false;
					//break;
				}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
