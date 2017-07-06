#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
	// your code goes here
	int a[10]={1};
	int b[10]={0};
	b[0]=b[9]=-1;
	a[0]=a[9]=0;
	char c,d;
	cin>>c>>d;
	int c_,d_;
	c_=(int)c-'a'+1;
	d_=(int)d-'0';
	for(int i=1;i<9;i++)a[i]=1;
	int ans=a[c_]*3+a[c_-1]*3+a[c_+1]*3-1;
	ans+=((a[c_])*(b[d_]+b[d_+1]+b[d_-1])+(a[c_+1])*(b[d_]+b[d_+1]+b[d_-1])+(a[c_-1])*(b[d_]+b[d_+1]+b[d_-1]));
	
	cout<<ans;
	
	return 0;
}