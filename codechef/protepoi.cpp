#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct  snake
{
	ll hx,hy,tx,ty;
};

ll n,k,m;
snake snakes[100007];

std::vector<pair<ll,ll> > hor,ver;

ll solve(std::vector<pair<ll,ll> > &v)
{
	ll lb=((n-k)/2) +1,ub=((n-k)/2) +k ;
	ll count = 0,l=1,u=lb-1,l2=lb-1,u2=lb-1;

	for (int i = 0; i < v.size(); ++i)
	{	
			// printf("%lld %lld %lld %lld %lld %lld\n", l,u,l2,u2,v[i].first,v[i].second);	
			if(v[i].first<=lb && v[i].second >= ub)
			{
				count = 1;
				return count;
			}
			if(u2>=ub)
			{
				// printf("here yet\n");
				count++;
				return count;
			}
			if(v[i].first > u2+1)
			{
				count = -1;
				// printf("here\n");
				return count;
			}
			if(v[i].second < lb || v[i].first > ub)
			{
				continue;
			}
			if(v[i].first <= u)
			{
				if(v[i].second > u2)
				{
					l2=v[i].first;
					u2=v[i].second;
				}
			}
			else if (v[i].first == u+1 && v[i].second > u2)
			{
				if(u>=lb)
					count++;
				l=v[i].first;
				u=l2=u2=v[i].second;
			}
			else
			{
				// printf("here\n");
				if(u2>=lb)
					{
						count++;
						// printf("not here %lld\n",count);
					}
				l=l2;
				u=u2;
				l2=v[i].first;
				u2=v[i].second;
			}

	}

	return count;

}


int main()
{

	int tc;

	ll hx,hy,tx,ty;

	scanf("%d",&tc);
	while(tc--)
	{
		ver.clear();
		hor.clear();
		scanf("%lld %lld %lld",&n,&k,&m);
		for (int i = 0; i < m; ++i)
		{
				scanf("%lld %lld %lld %lld",&snakes[i].hx,&snakes[i].hy,&snakes[i].tx,&snakes[i].ty);
		
					ver.push_back(make_pair(snakes[i].hy,snakes[i].ty));
					hor.push_back(make_pair(snakes[i].hx,snakes[i].tx));

		}

		ll lb=((n-k)/2) +1,ub=((n-k)/2) +k ;

		sort(ver.begin(), ver.end());
		sort(hor.begin(), hor.end());
		ll vcount =0;
		ll l=-1 ,u=-1 , l2=-1,u2=-1;
		

		ll vertical = solve(ver);
		ll horizontal = solve(hor);


		if(vertical ==-1 || horizontal == -1)
			printf("-1\n");
		else
			printf("%lld\n", vertical+horizontal);

		// printf("%lld\n", solve(ver) );
		// printf("%lld\n", solve(hor) );

	}
	
	return 0;
}
