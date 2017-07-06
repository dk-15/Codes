#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl printf("\n")

struct node {
	vector<int> adj;
};
vector<ll> depth(200005), height(200005), parent(200005);
vector<node> tree;

void dfs(ll u, ll p) {
	ll i,v;
	for(i=0; i<tree[u].adj.size();i++) {
		v = tree[u].adj[i];
		if (v != p) {
			depth[v] = depth[u] + 1;
			parent[v] = u;
			dfs(v,u);
			height[u] = max(height[u],height[v]+1);
		}
	}
}

void solve(ll n, ll x) {
	ll temp = x, min_depth = depth[x]/2 + 1, ans = -1;
	while(depth[temp] >= min_depth) {
		ans = max(ans, depth[temp]+height[temp]);
		temp = parent[temp];
	}
	printf("%I64d\n", 2*ans);
}

int main()
{
	ll n,x,u,v;
	scanf("%I64d %I64d", &n, &x);
	tree.resize(n+1);
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%I64d %I64d", &u, &v);
		tree[u].adj.push_back(v);
		tree[v].adj.push_back(u);
	}
	dfs(1,0);
	solve(n,x);
	return 0;
}
