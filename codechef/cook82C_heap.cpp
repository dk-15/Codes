#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::vector<pair<ll,ll> > heap;
std::vector<ll> ms;
// std::vector<ll> heap;

void heapify(pair<ll,ll> ele, ll idx ,ll n)
{
	if(idx>=n)return;

	pair<ll,ll> lc=((idx<<1)<n)?heap[idx<<1]:make_pair(-1,-1);
	pair<ll,ll> rc=(((idx<<1))+1<n)?heap[(idx<<1) + 1]:make_pair(-1,-1);
	pair<ll,ll> la=(lc.first>rc.first)?lc:rc;
	ll nxtIdx=(lc.first>rc.first)?idx<<1:(idx<<1)+1;

	if(la.first==-1 || la.first<ele.first)
		{
			heap[idx]=ele;
			return;
		}
	else(la.first > ele.first)
	{
		tmp=heap[idx];
		heap[idx]=heap[nxtIdx];
		heapify(ele,nxtIdx,n);
	}
}

void build_heap()
{
	for (int i = (heap.size()/2); i >=0; --i)
	{
		heapify(heap[i],i,heap.size());
	}
}

void pop(ll n)
{
	if(heap[0].second>1)
	{
		heap[0].second--;
		return;
	}
	heap[0]=heap[n-1];
	heapify(heap[0],0,n-1);
}
void push(ll ele,ll n)
{
	
}

void preprocess()
{
	sort(ms.begin(), ms.end());
	ll tmp=ms[0],ctr=1;
	for (int i = 1; i < ms.size(); ++i)
	{
		if(ms[i]==tmp){
			ctr++;
			continue;
		}
		heap.push_back(make_pair(tmp,ctr));
		tmp=m[i];
		ctr=1;
	}
	heap.push_back(make_pair(tmp,ctr));

}


int main()
{
	
	return 0;
}
