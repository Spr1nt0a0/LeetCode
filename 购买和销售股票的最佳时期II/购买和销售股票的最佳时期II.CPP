//假设有一个数组，其第i个元素是一支给定的股票在某一天i的价格，设计一个算法找出最大赢利点，你可以进行任意多次的交易，然而不能同时进行多次交易，在再次购买之前必须先销售该股票
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int maxprofit(vector<int>&prices)
{
	int max=0;
	int sum=0;
	for(int i=1;i<prices.size();i++)
	{
		int diff=prices[i]-prices[i-1];
		if(diff>0)
			sum+=diff;
	}
	return sum;
}
void main()
{
	int a[7]={24,56,21,15,67,20,81};
	std:vector<int> b(a,a+7);
	int c=maxprofit(b);
	cout<<"maxprofit:"<<c<<endl;
}