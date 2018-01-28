//给定两个二进制字符串，返回它们的加和
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string addbinary(string a,string b)
{
	int carry=0;
	string result;
	for(int i=a.size()-1,j=b.size()-1;i>=0 || j>=0;--i,--j)
	{
		int ai=i>=0? a[i]-'0':0;
		int bj=j>=0? b[j]-'0':0;
		int val=(ai+bj+carry)%2;
		carry=(ai+bj+carry)/2;
		result.insert(result.begin(),val+'0');
	}
	if(carry==1)
	{
		result.insert(result.begin(),'1');
	}
	return result;
}

void main ()
{
	string a="11";
	string b="1";
	string c=addbinary(a,b);
	cout<<"c="<<c<<endl;
}
