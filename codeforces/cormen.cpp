#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[503],b[503];

int main()
{
	int n,k,req;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	b[0]=a[0];
	for(int i=1;i<n;i++)
	{
		req=a[i]-a[i-1];
		b[i]=a[i]+req;
		a[i+1]=a[i+1]>req?a[i+1]-req:0;
		i++;
	}
}