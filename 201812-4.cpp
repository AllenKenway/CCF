#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
const long long MAX = 500200;
using namespace std;
struct Edge{
	int u,v,w;
	bool operator<(Edge &x)const
	{
		return w<x.w; 
	} 
}edge[MAX];
int pre[MAX];

int find(int x)
{
	int y=x;
	while(pre[y]!=y)
		y=pre[y];
	while(x!=y)
	{
		int temp=pre[x];
		pre[x]=y;
		x=temp;
	}
	return y;
}
int main()
{	
	int n,m,root;
	cin>>n>>m>>root;
	for(int i=0;i<=n;i++)
		pre[i]=i;
	int u,v,w;
	for(int i=0;i<m;i++)
		cin>>edge[i].u>>edge[i].v>>edge[i].w;

	sort(edge,edge+m);
	
	int count=0;
	int max=0;
	for(int i=0;i<m;i++)
	{
		int fu=find(edge[i].u);
		int fv=find(edge[i].v);
		if(fu!=fv)
		{
			pre[fu]=fv;
			max=edge[i].w;
			count++;
			if(count==n-1)
				break;
		}
	}
	cout<<max;
	return 0;
}
