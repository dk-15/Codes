#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int tc,n;
	string s[2];
	int fa[503];
	bool flag;

	cin>>tc;
	while(tc--)
	{
		cin>>n>>s[0]>>s[1];
		flag = true;
		for (int i = 0; i < n; ++i)
		{
				if(s[0][i]=='#'&&s[1][i]=='#')
				{
					fa[i]=2;
					continue;
				}
				else if (s[0][i]=='.'&&s[1][i]=='#')
				{
					fa[i]=-1;
				}
				else if (s[0][i]=='#'&&s[1][i]=='.')
				{
					fa[i]=1;
				}
				else
				{
					while(i<n)
					{
						if (s[0][i]=='.'&&s[1][i]=='.')
							i++;
						else
							break;
					}
					if(i!=n)
					{
						flag=false;
						break;
					}
				}

		}

		if(!flag)
		{
			printf("no\n");
			continue;
		}
		ll ptr=0;
		// for (int i = 0; i < n; ++i)
		// {
		// 		printf("%d ", fa[i]);
		// }
		// printf("\n");
		for (int i = 0; i < n; ++i)
		{
			// printf("%lld\n", ptr);
			if(fa[i]==2)
			{
				ptr=ptr*(-1);
				continue;
			}
			else //if(fa[i]==1)
			{
				if(i==0)
				{
					ptr=fa[i];
				}
				else
				{
					if(ptr==0 || ptr == fa[i])
					{
						ptr=fa[i];
					}
					else
					{
						flag=false;
						break;
					}
				}
			}

		}

		if (flag)
		{
				printf("yes\n");
		}
		else
		{
			printf("no\n");
		}

	}



	return 0;
}
