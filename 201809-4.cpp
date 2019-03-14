//运行超时
#include<iostream>
using namespace std;
int n;
int pre[300];
int next[300];

bool Solve(int i)
{
	int min = next[i-1] * 3 -pre[i-1] -pre[i-2];
	int max = (next[i-1]+1) * 3 -pre[i-1] -pre[i-2];
	if(max<=0)
		return false;
	int re = 0;
	for(int m = (min<=0)?1:min;m<max;m++)
	{
		pre[i]=m;
		if(i==n-1)
		{
			if(next[i] == ( pre[i] + pre[i-1] )/2)
				return true;
			else continue;
		}
		if(i == n-1)
			return false;
		re = Solve(i+1);
		if(!re)
			continue;
		else
			return true;
	}
	return false;
} 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>next[i];
	
	int re=0;
	for(int i=1;i<=(next[0])*2;i++)
	{	
		pre[0]=i;
		int min = next[0] * 2 -pre[0];
		int max = (next[0]+1) * 2 -pre[0];
		for(int j=min;j<max;j++)
		{
			pre[1] = j;
			re = Solve(2);
			if(re) break;
		}
		if(re) break;
	}
	
	if(re)
		for(int i=0;i<n;i++)
			cout<<pre[i]<<" ";
		
	return 0;
} 
