#include<iostream>
using namespace std;
#define max 10000
int n;
int pre[max];
int next[max];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>pre[i];
	
	for(int i=0;i<n;i++)
	{
		if(i-1>=0 && i+1<n)
			next[i] = (pre[i-1] + pre[i] + pre[i+1])/3;
		else if(i==0)
			next[i] = (pre[i] + pre[i+1])/2;
		else if(i==n-1)
			next[i] = (pre[i-1] + pre[i])/2;
	}
	
	for(int i=0;i<n;i++)
		cout<<next[i]<<" ";
		
	return 0;
} 
