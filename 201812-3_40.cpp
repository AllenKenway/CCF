#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <vector>
#include <list> 
#include <cstdlib>
#include <cstdio>  
#include <sstream>
#include <algorithm>
using namespace std;
long long n;
struct IP
{
	string addr;
	string numaddr;
	int len;
};

int pow[8] = {128,64,32,16,8,4,2,1};

bool SortByNum(struct IP& left,struct IP& right)
{
	return (left.addr<right.addr) || (left.addr==right.addr && left.len<=right.len);
}

int Change(string& str,string& numstr)
{
	int pos=0,pos1=0,pos2=0;
	int len = 0;
	int num[4];

	string s1="0",s2="0",s3="0",s4="0";
	
	pos = str.find(".");
	pos1 = str.find(".",pos+1);
	pos2 = str.find(".",pos1+1);
 
	if(pos >= 0)
	{
		s1 = str.substr(0,pos);
		if(pos1 >= 0)
		{
			s2 = str.substr(pos+1,pos1 - pos - 1);
			if(pos2 >= 0)
			{			
				s3 = str.substr(pos1+1,pos2 - pos1 - 1);
				s4 = str.substr(pos2+1,str.length());				
			}
			else
				s3 = str.substr(pos1+1,str.length());
		}
		else
			s2 = str.substr(pos+1,str.length());
	}
	else 
		s1=str;
	numstr = s1 + "." + s2 + "." + s3 + "." + s4;
	
	stringstream ss1(s1);
	ss1>>num[0];
	stringstream ss2(s2);
	ss2>>num[1];
	stringstream ss3(s3);
	ss3>>num[2];
	stringstream ss4(s4);
	ss4>>num[3];
	string ss;
	int i=0,j=0;
	str = "";
	while(i!=4)
	{
		j = 0;
		ss = "";
		while(j<8)
		{
			if(num[i]>=pow[j])
			{
				num[i] = num[0] - pow[j];
				ss += "1";
				len = 8 * (i+1);
			}
			else
				ss += "0";	
			j++;
		}
		str += ss;
		if(i!=3)
			str += ".";
		i++;
	}
	return len;
}


//ab的匹配集并集是否是a的匹配集
bool unionChild(struct IP& a,struct IP& b)
{
	if(a.len != b.len)
		return false;
	int n= a.len + a.len / 8;
	
	for(int i=0;i<n-1;i++)
	{
		if(a.addr[i] != b.addr[i])
			return false;
	}
	return a.addr[n-1]!=b.addr[n-1];
}

void Merge2(vector<struct IP> &ADDR)
{
	vector<struct IP>::iterator i = ADDR.begin(),j;
	for(;i!=ADDR.end();i++)
	{
		j = i+1;
		while(j!=ADDR.end())
		{
			if(!unionChild(*i,*j))
				break;
			ADDR.erase(j);
			(*i).len--;
			j = i+1;
		}
	}
}

//b是否是a的匹配子集 
bool isChild(struct IP& a,struct IP& b)
{
	if(a.len>=b.len)
		return false;
	int n= a.len + a.len / 8;
	for(int i=0;i<n;i++)
	{
		if(a.addr[i] != b.addr[i])
			return false;
	}
	return true;
}

void Merge1(vector<struct IP> &ADDR)
{
	vector<struct IP>::iterator i = ADDR.begin(),j;
	for(;i!=ADDR.end();i++)
	{
		j=i+1;
		while(j!=ADDR.end())
		{	
			if(!isChild(*i,*j))
			{
				break;
			}

			ADDR.erase(j);
			j = i + 1;
		}
	}
}


int main()
{
	cin>>n;	
	vector<struct IP> ADDR;
	struct IP Addr;
	while(n--)
	{
		cin>>Addr.addr;
		
		int re = Addr.addr.find("/");
		if(re >= 0)
		{
			string s_len = Addr.addr.substr(re+1,Addr.addr.length()-1);
			Addr.addr = Addr.addr.substr(0,re);
			stringstream sstr(s_len);
    		sstr >> Addr.len;
		}
		
		int len1 = Change(Addr.addr,Addr.numaddr);
		
		if(re<0)
			Addr.len = len1;	
		
		ADDR.push_back(Addr);
	}
	sort(ADDR.begin(),ADDR.end(),SortByNum);
	Merge1(ADDR);
	Merge2(ADDR);
	for(vector<struct IP>::iterator itor = ADDR.begin();itor != ADDR.end(); itor++)
	{			
		cout<<(*itor).numaddr<<"/"<<(*itor).len<<endl;
	}
}
