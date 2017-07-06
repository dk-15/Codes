#include <bits/stdc++.h>
using namespace std;
#define ll long long


std::vector<std::vector<int> > adj;
std::vector<ll> maxc;
int minr[100005],pa[100005],sp[100005],st[100005],et[100005],timer;

struct node
{
	ll val;
	node *left,*right;
 
	node():val(0),left(NULL),right(NULL){}
	node(int v, node *l, node *r):val(v),left(l),right(r){}

};

node *state[100005];

int build(node* &root,ll low,ll high) {
    if (low==high) {
        root->val = 0;
        return 0;
    }
    ll mid = low + (high-low) / 2;
    root->left = new node();
    root->right = new node();
    build(root->left, low, mid);
    build(root->right, mid+1, high);
    root->val = root->left->val + root->right->val;
    return 0;
}


int rUpdate(node* &prev, node* &cur, ll low, ll high, ll start, ll end) {
    if (low > end or  high < start or low > high)
        return 0;
    if (start <= low and high <= end) {
        cur->val = 0;
        return 0;
    }
    ll mid = low + (high-low) / 2;
 
    if (start > mid) {
        cur->right = new node();
        if (prev->val == 0) {
        	cur->left = new node();
        	rUpdate(cur->right,cur->right, mid+1, high, start, end);
        }
        else {
            cur->left = prev->left;
            rUpdate(prev->right, cur->right, mid+1, high, start, end);   
        }
    }
    else if (end <= mid) {
        cur->left = new node();
        if (prev->val == 0) {
        	cur->right = new node();
        	rUpdate(cur->left,cur->left, low, mid, start, end);
        }
        else {
            cur->right = prev->right; 
            rUpdate(prev->left,cur->left, low, mid, start, end);
        }
 
    }
    else {
        cur->left = new node();
        cur->right = new node();
        if (prev->val == 0) {
            rUpdate(cur->left,cur->left, low, mid, start, end);
            rUpdate(cur->right, cur->right, mid+1, high, start, end);
        }
        else {
            rUpdate(prev->left,cur->left, low, mid, start, end);
            rUpdate(prev->right, cur->right, mid+1, high, start, end);   
        }
    }
 
    cur->val = cur->left->val + cur->right->val;
    return 0;
}

ll query(node* root, ll low, ll high, ll start, ll end) {
    if (start > high or end < low or low > high)
       return 0;
    if (start <= low and high <= end)
       return root->val;
    if (root->val == 0) {
    	return 0;
    }
    ll mid =low+ (high-low) / 2;
    ll q1 = query(root->left,low,mid,start,end);
    ll q2 = query(root->right,mid+1,high,start,end);
    return q1+q2;
}


int pUpdate(node* &prev, node* &cur, ll low, ll high, ll index, ll value) {
    if (index > high or index < low or low > high)
        return 0;
    if (low == high) {
        cur->val = value + prev->val;
        return 0;
    }
    ll mid = low + (high-low) / 2;
    if(index>mid) {
        cur->right = new node();
 
        if (prev->val == 0) {
        	cur->left = new node();
        	pUpdate(cur->right,cur->right, mid+1, high, index, value);
        }
        else {
	        cur->left = prev->left;
	        pUpdate(prev->right,cur->right, mid+1, high, index, value);
        }
    }
    else if (index <= mid) {
        cur->left = new node();
 
        if (prev->val == 0) {
        	cur->right = new node();
        	pUpdate(cur->left,cur->left, low, mid, index, value);
        }
        else {
	        cur->right = prev->right;
	        pUpdate(prev->left,cur->left, low, mid, index, value);
        }
    }
    
    cur->val = cur->left->val + cur->right->val;
    return 0;
}
 

ll branch_broken(ll src, ll extra, ll size, ll cur_version) {
	ll query_u, query_spu, temp = src;
	//cerr<<temp<<" :::::::: "<< extra <<";;;;;;;;" << minr [temp];
	while (temp != 0 && query(state[cur_version], 1,size, st[minr [temp]], et[minr [temp]]) + extra <= maxc[minr [temp]]) {
		temp = pa[minr [temp]];
        //cerr<<":::::::::::"<<temp<<endl;
	}

	if (temp == 0) {
		return -1;
	}
   
	while (temp != -1) {
		query_u = query(state[cur_version], 1, size, st[temp], et[temp]);
		if (query_u + extra > maxc[temp])
			break;
		while (sp[temp] != -1) {
			query_u = query(state[cur_version], 1, size, st[temp], et[temp]);
			query_spu = query(state[cur_version], 1, size, st[sp[temp]], et[sp[temp]]);
			if (query_u + extra <= maxc[temp] && query_spu + extra > maxc[sp[temp]])
				break;
			temp = sp[temp];
		}
		temp = pa[temp];
	}
	return temp;

}
void print_tree(node* root, ll l, ll r) {
	if (root == NULL || l > r) {
		return;
	}
	ll mid = l + (r-l)/2;
    cerr << "[" << l << "," << r << "] ---> " << root->val << endl;
	print_tree(root->left, l, mid);
	
	print_tree(root->right, mid+1, r);
}
void dfs(int src, int minval)
{
	st[src]=++timer;
	minr[src] = (maxc[minval]<=maxc[src])?minval:src;

	ll temp=src;
	while(sp[temp]!=-1)
	{
		if(maxc[src]>=maxc[sp[temp]])
			break;
		temp=sp[temp];
	}
	sp[src]=sp[temp];

	for (int i = 0; i < adj[src].size()	; ++i)
	{
			dfs(adj[src][i],minr[src]);
	}

	et[src]=timer;

}
void preprocess(ll n)
{
	 state[0] = new node();
	 build(state[0], 1, n+1);
}

void newAcorns(ll n,ll s,ll cs)
{
	ll u,x;
	scanf("%lld%lld",&u,&x);
	ll broken_node = branch_broken(u, x, n+1, s);
	//cerr<<";;;;;;;;;;"<<broken_node<<"    "<<query(state[s], 1, n+1, st[u], et[u])<<endl;
	if (broken_node == -1) {
		pUpdate(state[s], state[cs], 1, n+1, st[u], x);
		printf("0\n");
	}
	else {
		rUpdate(state[s], state[cs], 1, n+1, st[broken_node], et[broken_node]);
		printf("%lld\n", broken_node);
	}
}


void birdSits(ll n, ll s, ll cs)
{
	ll u;
	scanf("%lld",&u);
	ll query_ans = query(state[s], 1, n+1, st[u], et[u]);
	printf("%lld\n", query_ans);

	rUpdate(state[s], state[cs], 1, n+1, st[u], et[u]);
}

int main()
{
	ll tc,n,m,p,w,s,type,u,x;
	scanf("%lld",&tc);

	while(tc--)
	{
		scanf("%lld %lld",&n,&m);
		adj.clear();maxc.clear();timer=0;
		adj.resize(n+1);
		maxc.resize(n+1);
		for (int i = 1; i <=n; ++i)
		{
				scanf("%lld%lld",&p,&w);
				adj[p].push_back(i);
				maxc[i]=w;
				sp[i]=p;
				pa[i]=p;
		}
        maxc[0]=1e18;
		sp[0]=pa[0]=-1;
		dfs(0,0);

		preprocess(n);
		for (int i = 1; i <= m; ++i)
		{
            //cerr<<i<<endl;
				scanf("%lld%lld",&s,&type);
				state[i] = new node();
				if(type == 1)
				{
					newAcorns(n,s,i);
				}
				else
				{
					birdSits(n,s,i);
				}
         cerr << "================================================\n";
         print_tree(state[i], 1, n+1);
         cerr << "================================================\n";
		}

	}

	return 0;
}
