#include <iostream>
using namespace std;
int r,y,g;
int n;
int main()
{
	cin>>r>>y>>g>>n;
	int time = 0;
	int f,t;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&f,&t);
		if(f == 0)
			time += t;
		else if(f == 1)
		{
			time += t;
		}
		else if(f == 2)
		{
			time += t + r;
		}
		else if(f == 3)
		{
			time += 0;
		}
	} 
	cout<<time;
} 
