#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define max 1000200
int n;
int time[max]={0}; 
int main()
{
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int i=a;i<b;i++)
			time[i]++;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		for(int i=a;i<b;i++)
			time[i]++;
	}

	int count=0;
	for(int i=0;i<max;i++)
		if(time[i]==2)
			count++;
	cout<<count<<endl;
	return 0;
} 
