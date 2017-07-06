#include <bits/stdc++.h>
using namespace std;
#define ll long long

std::vector<ll> primes;
ll sieve[1000006],arr[100005];
map<int,int> factors[1000006];
map<int,int>::iterator itr;


struct node
{
	ll val;
	node *left,*right;
 
	node():val(0),left(NULL),right(NULL){}
	node(int v, node *l, node *r):val(v),left(l),right(r){}
 
 
};

node *state[100005];

void primesieve()
{
	ll max = sqrt(1000004);
	for (int i = 2; i <= max; ++i)
	{
		if(!sieve[i])
		{
			for (int j = 2*i; j <=1000002; j+=i)
			{
				sieve[j]=i;
			}
		}
	}

    for (int i = 2; i <= 1000001; ++i)     {       
          if(!sieve[i])
			{   
              primes.push_back(i);   
              sieve[i]=i;
			} 
	    }
 }

void generateFactors()
{
 
	for(int i=2;i<1000001;++i)
	{
		if(sieve[i]==i)
			{
				factors[i][i]=1;
				continue;
			}
		ll num = i;
		ll ctr,fac;
		while(num!=1)
		{
			ctr=0;
			fac=sieve[num];
			while(num%fac == 0)
			{
				num/=fac;
				ctr++;
			}
 
			factors[i][fac]=ctr;
 
		}
	}
 
}


void build(node *n , int low ,int high)
{
	if(low==high)
		{
			itr=factors[arr[1]].find(primes[low]);
			n->val=(itr!=factors[arr[1]].end())?itr->second : 0;
			return ;
		}
 
		int mid = (low + high)>>1;
		n->left = new node();
		n->right = new node();
 
		build(n->left,low,mid);
		build(n->right,mid+1,high);
 
		n->val= n->left->val + n->right->val;
 
}


void upgrade(node *prev , node *cur , int low ,int high, int idx , int val)
{
	if(high < idx || low > idx || low > high)
		return;
 
	if(low==high)
	{
		cur->val = val+prev->val;
	}
 
	int mid = (low+high)>>1;
 
	if(idx<=mid)
	{
		if(cur->right==NULL)cur->right  = prev->right;
 
		if(cur->left ==NULL || cur->left==prev->left)cur->left = new node();
 
		upgrade(prev->left,cur->left,low,mid,idx,val);
 
	}
	else
	{
		if(cur->left==NULL)cur->left  = prev->left;
 
 		if(cur->right ==NULL || cur->right==prev->right)cur->right = new node();

		upgrade(prev->right,cur->right,mid+1,high,idx,val);
	}
 
	cur->val= cur->left->val+cur->right->val;
 
}


ll query(node *root, int low , int high , int start, int end)
{
	if(low>end || high < start || low > high)
		return 0;
	if(low>=start && high<=end)
	{
		return root->val;
	}

	int mid = low + (high-low)/2 ; 
	ll q1 = query(root->left,low,mid,start,end);
	ll q2 = query(root->right,mid+1,high,start,end);

	return q1+q2;

}


void createPersistence(ll n)
{
	state[1] = new node();
	build(state[1],0,primes.size()-1);
	for (int i = 2; i <= n; ++i)
	{
			state[i]=new node();
			itr = factors[arr[i]].begin();
			while(itr!= factors[arr[i]].end())
			{
				upgrade(state[i-1],state[i],0,primes.size()-1,lower_bound(primes.begin(), primes.end(),itr->first)-primes.begin(),itr->second);
			}
	}
}


void solve(ll l,ll r,ll x, ll y)
{
	ll fp = lower_bound(primes.begin(), primes.end(),x)-primes.begin();
	ll lp = lower_bound(primes.begin(), primes.end(),y)-primes.begin();
	if(lp ==primes.size() || primes[lp]>y)
		lp--;
	if(fp == primes.size() || primes[fp]>primes[lp])
		{
			printf("0\n");
			return ;
		}

	ll rightans  = query(state[r],0,primes.size()-1,fp,lp);
	ll leftans   = (l>1)?query(state[l],0,primes.size()-1,fp,lp):0;

	printf("%lld\n",rightans-leftans );

}



int main()
{
	primesieve();
	generateFactors();

	ll n,q,l,r,x,y;
	scanf("%lld",&n);

	for (int i = 1; i <= n; ++i)
	{
			scanf("%lld",&arr[i]);
	}

	createPersistence(n);

	scanf("%lld",&q);

	for (int i = 0; i < q; ++i)
	{
			scanf("%lld %lld %lld %lld",&l,&r,&x,&y);
			solve(l,r,x,y);
	}

	return 0;
}
