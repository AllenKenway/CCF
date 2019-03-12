#include <iostream>
using namespace std;
int r,y,g;
int n;
int main()
{
	cin>>r>>y>>g>>n;
	long long total = 0;
	long long f = 0,time =0;
	while(n--)
	{
		cin>>f>>time;
		if(f != 0)
		{
			time -= total%(r+g+y);
			//time -= total;�ᳬʱ 
			while(time <= 0)
			{
				if(f == 1)
				{
					time += g;
					f = 3;
				}
				else if(f == 2)
				{
					time += r;
					f = 1;
				}
				else if(f == 3)
				{
					time += y;
					f = 2;
				}
			}
		}		
		if(f == 0)
			total += time;
		else if(f == 1)
		{
			total += time;
		}
		else if(f == 2)
		{
			total += time + r;
		}
		else if(f == 3)
		{
			total += 0;
		}
	} 
	cout<<total;
} 
